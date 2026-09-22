// This program creates a file containing three fixed-size records.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd = open("records.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    char records[3][20] = {
        "Record 1",
        "Record 2",
        "Record 3"
    };

    for (int i = 0; i < 3; i++)
    {
        write(fd, records[i], 20);
    }

    close(fd);

    printf("Three records created.\n");

    return 0;
}
