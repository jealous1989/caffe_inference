
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>

int main(int argv, char ** argc)
{
	int fd = open(argc[1], O_RDONLY);
	char out[256] ;
   	sprintf(out, "EE_%s_E",argc[1]);

	int outf = open(out, O_RDWR|O_CREAT, 0666);

	while(1)
	{
		unsigned char p[256];
		ssize_t n= read(fd,  p , 256);
	
		if(n <=0)
			break;

		for(int i = 0 ; i < n ;i++)
			p[i] ^= 0x27;
		write(outf, p, n);
		
	}	

	return 1;	
}

