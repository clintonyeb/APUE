#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char const *argv[])
{
    umask(0);
    if((creat("foo.txt", RWRWRW)) < 0 ) {
        err_sys("Error creating file");
    }

    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if((creat("bar.txt", RWRWRW)) < 0 ) {
        err_sys("Error creating file");
    }

    return 0;
}
