// 26. Write a program to execute an executable program.
// b. pass some input to an executable program. (for example execute an executable of $./a.out name)

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s name\n", argv[0]);
        return 1;
    }

    execl("./printname", "printname", argv[1], NULL);

    perror("execl");
    return 1;
}
