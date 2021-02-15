#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
    char buf[1025]; 
    int opt; 
    int append = 0; 
    int readCount;
    int fd;

    while ((opt = getopt(argc, argv, "a")) != -1) 
    {
        switch (opt) 
        {
            case 'a':
                append = 1;
                break;
            default:
                printf("Option is invalid\n");
                break;
        }

    }

    if (append) 
    { 
        fd = open(argv[optind], O_CREAT | O_RDWR | O_APPEND , S_IRWXU);

    } 
    else 
    {
        fd = open(argv[optind], O_CREAT | O_RDWR | O_TRUNC , S_IRWXU);
    }

    do
    {
        readCount = read(fileno(stdin), &buf, 5);
        write(fileno(stdout),&buf,5);
        write(fd,&buf,5);
    }
    while(readCount==5);

    close(fd);
    return 0;
}