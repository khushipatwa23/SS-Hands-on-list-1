// Identify the type of a file using stat()

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct stat file_info;

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &file_info) == -1) {
        perror("stat");
        return 1;
    }

    if (S_ISREG(file_info.st_mode))
        printf("%s is a regular file.\n", argv[1]);

    else if (S_ISDIR(file_info.st_mode))
        printf("%s is a directory.\n", argv[1]);

    else if (S_ISLNK(file_info.st_mode))
        printf("%s is a symbolic link.\n", argv[1]);

    else if (S_ISFIFO(file_info.st_mode))
        printf("%s is a FIFO (named pipe).\n", argv[1]);

    else if (S_ISSOCK(file_info.st_mode))
        printf("%s is a socket.\n", argv[1]);

    else if (S_ISCHR(file_info.st_mode))
        printf("%s is a character device.\n", argv[1]);

    else if (S_ISBLK(file_info.st_mode))
        printf("%s is a block device.\n", argv[1]);

    else
        printf("%s is an unknown file type.\n", argv[1]);

    return 0;
}
