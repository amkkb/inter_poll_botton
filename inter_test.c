#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>

int main(int argc, char **argv)
{
    int fd,ret = 0;
    int key_val = 0;
    struct pollfd fds;   
    fd = open("/dev/key_driver",O_RDWR);
    if(fd < 0)
    {   
         printf("open device failed\n");
         return -1;    
    }
    else
    {
        printf("open success\n");
    }
		fds.fd = fd;
    fds.events = POLLIN;
    while(1)
    {
    		ret = poll(&fds,1,3000);
        if(!ret)
            printf("time out\n");
        else
        	{
        		 	read(fd,&key_val,1);
			        printf("key_val = 0x%x\n",key_val);
			        
        	}
       
    }

    return 0;

}
