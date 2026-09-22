// This program opens a file and applies a read lock on the entire file.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd = open("lockfile.txt", O_RDWR | O_CREAT, 0666);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    struct flock lock;

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    printf("Trying to acquire read lock...\n");

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Read lock acquired.\n");
    printf("PID = %d\n", getpid());

    printf("Press Enter to release the lock...\n");
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Read lock released.\n");

    close(fd);
    return 0;
}
