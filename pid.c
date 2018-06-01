#include "apue.h"
#define BUFFSIZE 4096

int
main (int argc, char *argv[]){
    char buf[BUFFSIZE];

    printf("Process ID: %ld\n", (long)getpid());
    printf("Working directory: %s\n", getcwd(buf, BUFFSIZE));    
    return 0;
}