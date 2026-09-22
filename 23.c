// Create a zombie process
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
        return 0;
    } else {
        printf("Parent: PID = %d\n", getpid());
        printf("Child PID = %d\n", pid);

        sleep(30);
    }

    return 0;
}
