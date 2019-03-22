// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// Author: kenton@google.com (Kenton Varda)
//  Based on original Protocol Buffers design by
//  Sanjay Ghemawat, Jeff Dean, and others.
//
// This file contains common implementations of the interfaces defined in
// zero_copy_stream.h which are only included in the full (non-lite)
// protobuf library.  These implementations include Unix file descriptors
// and C++ iostreams.  See also:  zero_copy_stream_impl_lite.h

#ifndef GOOGLE_PROTOBUF_IO_ZERO_COPY_STREAM__IMPL_H__
#define GOOGLE_PROTOBUF_IO_ZERO_COPY_STREAM__IMPL_H__

#include <string>
#include <iosfwd>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/stubs/common.h>


namespace google {
namespace protobuf {
namespace io {


// ===================================================================

// A ZeroCopyInputStream which reads from a file descriptor.
//
// EncStream is preferred over using an ifstream with IstreamInputStream.
// The latter will introduce an extra layer of buffering, harming performance.
// Also, it's conceivable that EncStream could someday be enhanced
// to use zero-copy file descriptors on OSs which support them.
class LIBPROTOBUF_EXPORT EncStream : public ZeroCopyInputStream {
 public:
  // Creates a stream that reads from the given Unix file descriptor.
  // If a block_size is given, it specifies the number of bytes that
  // should be read and returned with each call to Next().  Otherwise,
  // a reasonable default is used.
  explicit EncStream(int file_descriptor, int block_size = -1);
  ~EncStream();

  // Flushes any buffers and closes the underlying file.  Returns false if
  // an error occurs during the process; use GetErrno() to examine the error.
  // Even if an error occurs, the file descriptor is closed when this returns.
  bool Close();

  // By default, the file descriptor is not closed when the stream is
  // destroyed.  Call SetCloseOnDelete(true) to change that.  WARNING:
  // This leaves no way for the caller to detect if close() fails.  If
  // detecting close() errors is important to you, you should arrange
  // to close the descriptor yourself.
  void SetCloseOnDelete(bool value) { copying_input_.SetCloseOnDelete(value); }

  // If an I/O error has occurred on this file descriptor, this is the
  // errno from that error.  Otherwise, this is zero.  Once an error
  // occurs, the stream is broken and all subsequent operations will
  // fail.
  int GetErrno() { return copying_input_.GetErrno(); }

  // implements ZeroCopyInputStream ----------------------------------
  bool Next(const void** data, int* size);
  void BackUp(int count);
  bool Skip(int count);
  int64 ByteCount() const;

 private:
  class LIBPROTOBUF_EXPORT CopyingEncStream : public CopyingInputStream {
   public:
    CopyingEncStream(int file_descriptor);
    ~CopyingEncStream();

    bool Close();
    void SetCloseOnDelete(bool value) { close_on_delete_ = value; }
    int GetErrno() { return errno_; }

    // implements CopyingInputStream ---------------------------------
    int Read(void* buffer, int size);
    int Skip(int count);

   private:
    // The file descriptor.
    const int file_;
    bool close_on_delete_;
    bool is_closed_;

    // The errno of the I/O error, if one has occurred.  Otherwise, zero.
    int errno_;

    // Did we try to seek once and fail?  If so, we assume this file descriptor
    // doesn't support seeking and won't try again.
    bool previous_seek_failed_;

    GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(CopyingEncStream);
  };

  CopyingEncStream copying_input_;
  CopyingInputStreamAdaptor impl_;

  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(EncStream);
};

// ===================================================================


}  // namespace io
}  // namespace protobuf

}  // namespace google
#endif  // GOOGLE_PROTOBUF_IO_ZERO_COPY_STREAM_IMPL_H__
