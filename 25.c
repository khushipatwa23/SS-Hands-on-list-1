//Write a program to create three child processes. 
//The parent should wait for a particular child (use waitpid system call).
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child[3];

    for (int i = 0; i < 3; i++) {
        child[i] = fork();

        if (child[i] < 0) {
            perror("fork");
            return 1;
        }

        if (child[i] == 0) {
            printf("Child %d: PID = %d\n", i + 1, getpid());
            sleep((i + 1) * 2);
            printf("Child %d exiting\n", i + 1);
            return 0;
        }
    }

    printf("Parent: waiting for Child 2 (PID = %d)\n", child[1]);

    waitpid(child[1], NULL, 0);

    printf("Parent: Child 2 has terminated\n");

    return 0;
}
