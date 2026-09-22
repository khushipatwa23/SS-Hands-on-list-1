// 26. Write a program to execute an executable program.
// a. use some executable program

#include <stdio.h>
#include <unistd.h>

int main()
{
    execl("/bin/ls", "ls", NULL);

    perror("execl");
    return 1;
}
