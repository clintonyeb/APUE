
#include <fcntl.h>
#include "apue.h"

int main(int argc, char const *argv[])
{
    int fd;
    char* buff1 = "abcdefjij";
    char* buff2 = "ABCDEFGHIJ";

    if((fd = creat("file.hole", FILE_MODE)) < 0)
        err_sys("could not create file");

    if((write(fd, buff1, 10)) < 10)
        err_sys("write error");
    if((lseek(fd, 16384, SEEK_SET)) == -1)
        err_sys("seek error");
    
    if((write(fd, buff2, 10)) < 10)
        err_sys("write error");

    printf("Seek position: %ld", lseek(fd, 0, SEEK_CUR));
    return 0;
}
