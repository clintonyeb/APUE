#include "apue.h"
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

static void sig_int(int);

int
main(){
    char buff[MAXLINE];
    pid_t pid;
    int status;
    const char* prompt = "%% ";
    char* cmd;
    char* arg;
    char* args[10];
    int i;
    int shdExit = 0;

    if(signal(SIGINT, sig_int) == SIG_ERR){
        err_sys("signal error");
    }

    printf(prompt);
    
    while((fgets(buff, MAXLINE, stdin)) != NULL && !shdExit) {
        if(buff[strlen(buff) - 1] == 10)
            buff[strlen(buff) - 1] = 0;
        if((pid = fork())< 0){
            err_sys("fork error");
        } else if (pid == 0){
            cmd = strtok(buff, " ,.-");
            if(cmd == NULL){
                err_sys("cmd missen");
                return -1;
            }
            if(!(strcmp(cmd, "exit"))) {
                shdExit = 1;
                break;
            };
           
            i = 0;
            args[i] = cmd;
            arg = strtok(NULL, " ,.-");
            while(arg != NULL){
                i++;
                if(strlen(arg) > 0) args[i] = arg;
                arg = strtok(NULL, " ,.-");
            }
            execvp(cmd, args);
            err_ret("couldn’t execute: %s", cmd);
            exit(127);
        } else {
            wait(&status);
        }

        if(!shdExit)
            printf(prompt);
        else
            exit(0);
    }
    return 0;
}

static void sig_int(int signal){
    printf("\nInvalid key. Press ^D to exit or type exit\n");
}