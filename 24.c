//Creating an orphan process
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child: PID = %d\n", getpid());
        printf("Child's initial Parent PID = %d\n", getppid());

        sleep(5);

        printf("Child's new Parent PID = %d\n", getppid());
    } else {
        printf("Parent: PID = %d\n", getpid());
        sleep(2);
        printf("Parent exiting...\n");
    }

    return 0;
}
