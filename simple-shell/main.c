#include <string.h>
#include <stdlib.h>
#include "shell.h"

#define MAX_BUFFER 256

int makeargv(char *s, char *delimiters, char ***argvp);

int main (int argc, char *argv[])
{
    char inbuf[MAX_BUFFER];
    char **chargv;
    int i;

    for(;;) {
	gets(inbuf);
       if (strcmp(inbuf, QUIT_STRING) == 0)
          break;
       else {
          if (fork() == 0) {
             if (makeargv(inbuf, BLANK_STRING, &chargv) > 0)
	     { 
                execvp(chargv[0], chargv);
	     }
          }
          wait(NULL);
       } 
    }   
    return 0;
}


int makeargv(char *s, char *delimiters, char ***argvp)
{
   char *t;
   char *snew;
   int numtokens;
   int i;
    /* snew is real start of string after skipping leading delimiters */
   snew = s + strspn(s, delimiters);
                              /* create space for a copy of snew in t */
   if ((t = calloc(strlen(snew) + 1, sizeof(char))) == NULL) {
      *argvp = NULL;
      numtokens = -1;
   } else {                     /* count the number of tokens in snew */
      strcpy(t, snew);
      if (strtok(t, delimiters) == NULL)
         numtokens = 0;
      else
         for (numtokens = 1; strtok(NULL, delimiters) != NULL;
              numtokens++)
              ;  
                /* create an argument array to contain ptrs to tokens */
      if ((*argvp = calloc(numtokens + 1, sizeof(char *))) == NULL) {
         free(t);
         numtokens = -1;
      } else {            /* insert pointers to tokens into the array */
         if (numtokens > 0) {
            strcpy(t, snew);
            **argvp = strtok(t, delimiters);
            for (i = 1; i < numtokens + 1; i++)
               *((*argvp) + i) = strtok(NULL, delimiters);
         } else {
           **argvp = NULL;
           free(t);
         }
      }
   }   
   return numtokens;
}
