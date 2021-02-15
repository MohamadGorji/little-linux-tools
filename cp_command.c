#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd1 = open(argv[1], O_RDWR | O_CREAT , S_IRWXU);
    int fd2 = open(argv[2], O_RDWR | O_CREAT , S_IRWXU);
    int readCount = 5;
    char buf[1024];
    do
    {
        readCount = read (fd1,&buf,5);
        write(fd2,&buf,5);
    }
    while(readCount==5);
    close(fd1);
    close(fd2);
    return 0;

}