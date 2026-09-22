// This program opens a file in read-write mode.
// It writes 10 bytes, moves the file pointer by 10 bytes using lseek(),
// and writes another 10 bytes.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    off_t position;

    fd = open("file10.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    write(fd, "1234567890", 10);

    position = lseek(fd, 10, SEEK_CUR);

    if (position == -1)
    {
        perror("lseek");
        close(fd);
        return 1;
    }

    printf("lseek return value: %ld\n", (long)position);

    write(fd, "ABCDEFGHIJ", 10);

    close(fd);

    return 0;
}
