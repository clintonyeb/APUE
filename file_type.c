#include <sys/stat.h>
#include "apue.h"


int main(int argc, char const *argv[])
{
    char* mess;
    struct stat buf;
    int8_t i;
    mode_t mode;

    for(i = 1; i < argc; i++)
    {
        if(lstat(argv[i], &buf) < 0){
            err_ret("lstat error");
            continue;
        } 
        printf("Mode of %s: ", argv[i]);

        mode = buf.st_mode;
        if(S_ISREG(mode)) {
            mess = "regular";
        }
        else if (S_ISDIR(mode))
        {
            mess = "directory";
        }
        else if (S_ISCHR(mode))
        {
            mess = "character special";
        }
        else if (S_ISBLK(mode))
        {
            mess = "block special";
        }
        else if (S_ISFIFO(mode))
        {
            mess = "FIFO";
        }
        else if (S_ISLNK(mode))
        {
            mess = "symbolic link";
        }
        else if (S_ISSOCK(mode))
        {
            mess = "socket";
        } 
        else
        {
            mess = "unknown";
        }
        
        printf("%s\n", mess);
    }
    
    return 0;
}
