#define _GNU_SOURCE

#include <string.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>

void dirname_basename(char *filename)
{
    printf("    Original filename: %s", filename);

    char *copyForDir = strdup(filename);
    char *dir = dirname(copyForDir);

    printf("    Directory Name: %s", dir);

    char *copyForBase = strdup(filename);
    char *base = basename(copyForBase);

    printf("    Base Name: %s", base);

    printf("    Reconstructed: %s/%s", dir, base);

    free(copyForBase);
    free(copyForDir);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    dirname_basename("/home/scully/xfile.txt");
    dirname_basename("test.txt");
    dirname_basename("/home/scully");
    dirname_basename("/home/");
    dirname_basename("///home/");
    dirname_basename("///home/");
    dirname_basename("//./home/");

    dirname_basename("/home");

    // Some special cases
    dirname_basename("/");
    dirname_basename(".");
    dirname_basename("..");

    // Try some other odd things...
    dirname_basename("./././");
    dirname_basename(".././");

    printf("Reconstructed versions are: dirname + '/' + basename\n");
    printf("The reconstructed version should be functionally equivalent to the original filename (although the actual path may be different.)");
    return 0;
}
