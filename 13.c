//x Wait for input on STDIN for 10 seconds using select()

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int result;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input on STDIN for 10 seconds...\n");
    fflush(stdout);

    result = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select");
        return 1;
    }
    else if (result == 0) {
        printf("No data available on STDIN within 10 seconds.\n");
    }
    else {
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            printf("Data is available on STDIN within 10 seconds.\n");
        }
    }

    return 0;
}
