// Find the opening mode of a file using fcntl()

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd, flags, mode;

    fd = open("test.txt", O_RDWR);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    flags = fcntl(fd, F_GETFL);

    if (flags == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    mode = flags & O_ACCMODE;

    if (mode == O_RDONLY)
        printf("File opened in read-only mode\n");
    else if (mode == O_WRONLY)
        printf("File opened in write-only mode\n");
    else if (mode == O_RDWR)
        printf("File opened in read-write mode\n");

    close(fd);

    return 0;
}
