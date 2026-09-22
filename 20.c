// This program displays its PID and current nice value.

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
    printf("PID: %d\n", getpid());
    printf("Nice value: %d\n", getpriority(PRIO_PROCESS, 0));

    printf("Press Enter to exit...\n");
    getchar();

    return 0;
}
