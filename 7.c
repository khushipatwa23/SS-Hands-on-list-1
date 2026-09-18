// This program copies the contents of file1 into file2.
// It uses open(), read(), write(), and close() system calls.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd1, fd2;
    char buffer[100];
    int n;


    fd1 = open("file1", O_RDONLY);

    if (fd1 == -1)
    {
        perror("Error opening file1");
        return 1;
    }


    fd2 = open("file2", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd2 == -1)
    {
        perror("Error creating file2");
        close(fd1);
        return 1;
    }


    while ((n = read(fd1, buffer, sizeof(buffer))) > 0)
    {
        write(fd2, buffer, n);
    }


    close(fd1);
    close(fd2);

    printf("File copied successfully.\n");

    return 0;
}
