// Parent and child process both write to the same file
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        write(fd, "Child writing\n", 14);
    } else {
        write(fd, "Parent writing\n", 15);
    }

    close(fd);

    return 0;
}
