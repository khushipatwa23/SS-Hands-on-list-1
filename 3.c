#include <stdio.h>
#include <fcntl.h>

int main() {
    int fd;

    fd = creat("sample.txt", 0644);

    if (fd == -1) {
        perror("creat");
        return 1;
    }

    printf("File descriptor: %d\n", fd);

    return 0;
}
