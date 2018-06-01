#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("UserId: %d, GroupId: %d", getuid(), getgid());
    return 0;
}
