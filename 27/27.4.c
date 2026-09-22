// 27. Write a program to execute ls -Rl by the following system calls
// d. execv

#include <stdio.h>
#include <unistd.h>

int main()
{
    char *args[] = {"ls", "-Rl", NULL};

    execv("/bin/ls", args);

    perror("execv");
    return 1;
}
