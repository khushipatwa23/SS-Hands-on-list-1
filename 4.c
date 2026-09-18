// This program opens an existing file in read-write mode.
// It also demonstrates the O_EXCL flag.
// O_EXCL is effective when used together with O_CREAT.
// If the file already exists, open() fails.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    // Open sample.txt with read and write permission.
    fd = open("sample.txt", O_RDWR);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    printf("File opened successfully.\n");
    printf("File descriptor: %d\n", fd);

    close(fd);

    // Try opening the same file with O_CREAT and O_EXCL.
    // O_EXCL makes the operation fail if the file already exists.
    fd = open("sample.txt", O_RDWR | O_CREAT | O_EXCL, 0644);

    if (fd == -1) {
        perror("O_EXCL");
    } else {
        printf("File created successfully.\n");
        close(fd);
    }

    return 0;
}
