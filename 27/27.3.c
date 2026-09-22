// 27. Write a program to execute ls -Rl by the following system calls
// c. execle

#include <stdio.h>
#include <unistd.h>

int main()
{
    char *envp[] = {
        "PATH=/bin:/usr/bin",
        NULL
    };

    execle("/bin/ls", "ls", "-Rl", NULL, envp);

    perror("execle");
    return 1;
}
