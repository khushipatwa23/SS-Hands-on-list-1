// Duplicate a file descriptor using dup, dup2 and fcntl,
// then write through both descriptors and verify the file contents.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd, fd_dup, fd_dup2, fd_fcntl;

    // Open file in append mode
    fd = open("test.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    // a) Duplicate using dup()
    fd_dup = dup(fd);

    if (fd_dup == -1) {
        perror("dup");
        return 1;
    }

    write(fd, "Original FD\n", 12);
    write(fd_dup, "dup FD\n", 7);

    printf("dup(): fd = %d, duplicated fd = %d\n", fd, fd_dup);

    // b) Duplicate using dup2()
    fd_dup2 = dup2(fd, 10);

    if (fd_dup2 == -1) {
        perror("dup2");
        return 1;
    }

    write(fd, "Original FD - dup2\n", 19);
    write(fd_dup2, "dup2 FD\n", 8);

    printf("dup2(): fd = %d, duplicated fd = %d\n", fd, fd_dup2);

    // c) Duplicate using fcntl()
    fd_fcntl = fcntl(fd, F_DUPFD, 0);

    if (fd_fcntl == -1) {
        perror("fcntl");
        return 1;
    }

    write(fd, "Original FD - fcntl\n", 20);
    write(fd_fcntl, "fcntl FD\n", 9);

    printf("fcntl(): fd = %d, duplicated fd = %d\n",
           fd, fd_fcntl);

    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);

    printf("\nData has been appended to test.txt\n");

    return 0;
}
