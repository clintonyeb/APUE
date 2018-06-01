#include <string.h>
#include <stdio.h>

char* removeTrainingDelimeter(const char* const str, const char* const delim){
    return str + strspn(str, delim); 
}

char * copy

int main(int argc, char const *argv[])
{
    char* message = "      hello world    ";
    printf("%s", removeTrainingDelimeter(message, ""));
    
    return 0;
}


