// This program locks the ticket file, reads the ticket number,
// increments it, prints the new number, and releases the lock.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd = open("ticket.txt", O_RDWR);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    printf("Waiting for write lock...\n");

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    int ticket;

    lseek(fd, 0, SEEK_SET);
    read(fd, &ticket, sizeof(ticket));

    ticket++;

    printf("New ticket number: %d\n", ticket);

    lseek(fd, 0, SEEK_SET);
    write(fd, &ticket, sizeof(ticket));

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);

    return 0;
}
