// This program creates five files and keeps running in an infinite loop.
// The files remain open so their file descriptors can be checked
// in /proc/<PID>/fd.

#include <stdio.h>
#include <fcntl.h>

int main() {
    int fd[5];

    // Create five files.
    for (int i = 0; i < 5; i++) {
        char filename[20];

        sprintf(filename, "file%d.txt", i + 1);

        fd[i] = creat(filename, 0644);

        if (fd[i] == -1) {
            perror("creat");
            return 1;
        }

        printf("%s created with FD = %d\n", filename, fd[i]);
    }

    // Infinite loop keeps the process running.
    while (1) {
    }

    return 0;
}
