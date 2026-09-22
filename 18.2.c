// This program locks a selected record, modifies it,
// and then releases the record lock.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd = open("records.txt", O_RDWR);

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

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (record_no - 1) * 20;
    lock.l_len = 20;
    lock.l_pid = getpid();

    printf("Waiting for write lock on Record %d...\n", record_no);

    fcntl(fd, F_SETLKW, &lock);

    printf("Write lock acquired.\n");

    char data[20];

    lseek(fd, (record_no - 1) * 20, SEEK_SET);
    read(fd, data, 20);

    printf("Old record: %s\n", data);

    printf("Enter new record: ");
    scanf(" %[^\n]", data);

    lseek(fd, (record_no - 1) * 20, SEEK_SET);
    write(fd, data, 20);

    printf("Record updated.\n");

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Lock released.\n");

    close(fd);

    return 0;
}
