// This program locks a selected record for reading,
// reads the record, and then releases the lock.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd = open("records.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    int record_no;

    printf("Enter record number (1-3): ");
    scanf("%d", &record_no);

    if (record_no < 1 || record_no > 3)
    {
        printf("Invalid record number.\n");
        close(fd);
        return 1;
    }

    struct flock lock;

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (record_no - 1) * 20;
    lock.l_len = 20;
    lock.l_pid = getpid();

    printf("Waiting for read lock on Record %d...\n", record_no);

    fcntl(fd, F_SETLKW, &lock);

    printf("Read lock acquired.\n");

    char data[21] = {0};

    lseek(fd, (record_no - 1) * 20, SEEK_SET);
    read(fd, data, 20);

    printf("Record %d: %s\n", record_no, data);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Lock released.\n");

    close(fd);

    return 0;
}
