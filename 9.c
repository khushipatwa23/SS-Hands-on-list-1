// This program displays various information about a given file.
// It uses the stat() system call to obtain file information.
// It displays inode, hard links, UID, GID, size, block size, blocks, and timestamps.

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    struct stat file;
    char filename[100];

    printf("Enter filename: ");
    scanf("%99s", filename);

    if (stat(filename, &file) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("a. Inode number       : %ld\n", file.st_ino);
    printf("b. Hard links         : %d\n", file.st_nlink);
    printf("c. UID                : %d\n", file.st_uid);
    printf("d. GID                : %d\n", file.st_gid);
    printf("e. Size               : %ld bytes\n", file.st_size);
    printf("f. Block size         : %d bytes\n", file.st_blksize);
    printf("g. Number of blocks   : %ld\n", file.st_blocks);
    printf("h. Last access        : %s", ctime(&file.st_atime));
    printf("i. Last modification  : %s", ctime(&file.st_mtime));
    printf("j. Last change        : %s", ctime(&file.st_ctime));

    return 0;
}
