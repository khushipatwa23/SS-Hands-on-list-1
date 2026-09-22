// 27. Write a program to execute ls -Rl by the following system calls
// e. execvp

#include <stdio.h>
#include <unistd.h>

int main()
{
    char *args[] = {"ls", "-Rl", NULL};

    execvp("ls", args);

    perror("execvp");
    return 1;
}
