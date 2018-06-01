#include "apue.h"
#include <dirent.h>

int
main(int argc, char *argv[])
{
	DIR				*dp;
	struct dirent	*dirp;
    char* dirname;

	if (argc != 2)
		dirname = ".";
    else
        dirname = argv[1];

	if ((dp = opendir(dirname)) == NULL)
		err_sys("can't open %s", dirname);
	while ((dirp = readdir(dp)) != NULL)
		printf("%s ", dirp->d_name);

	closedir(dp);
	exit(0);
}
