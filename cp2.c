#include "apue.h"

int
main (int argc, char *argv[]){
    int c;

    while((c = getc(stdin)) != EOF) {
        if(putc(c, stdout) == EOF) {
            err_sys("write error");
        }
    }

    if(ferror(stdin)){
        err_sys("read error");
    }
    return 0;
}