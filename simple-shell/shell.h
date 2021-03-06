#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <limits.h>

#define STDMODE 0600
#define DELIMITERSET "$$ "

#ifndef MAX_CANON
#define MAX_CANON 256
#endif 
#define TRUE 1
#define FALSE 0
#define BLANK_STRING  " "
#define PROMPT_STRING ">>"
#define QUIT_STRING "q"
#define BACK_STRING "&"
#define PIPE_STRING "|"
#define NEWLINE_STRING "\n"
#define IN_REDIRECT_SYMBOL '<'
#define OUT_REDIRECT_SYMBOL '>'
#define NULL_SYMBOL '\0'
#define PIPE_SYMBOL '|'
#define BACK_SYMBOL '&'
#define NEWLINE_SYMBOL '\n'
 
int makeargv(char *s, char *delimiters, char ***argvp);
int parsefile(char *inbuf, char delimiter, char **v);
int redirect(char *infilename, char *outfilename);
void executecmdline(char *cmd);
int connectpipeline(char *cmd, int frontfd[], int backfd[]);
