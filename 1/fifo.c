#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    if (mkfifo("myfifo2", 0666) == -1) {
        perror("mkfifo");
        return 1;
    }

    printf("FIFO created successfully.\n");

    return 0;
}
