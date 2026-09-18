// Reads input from STDIN and displays it on STDOUT.
// Uses only the read() and write() system calls for input/output.

#include <unistd.h>

int main()
{
    char buffer[100];
    int n;

    // Read data from STDIN (file descriptor 0).
    n = read(0, buffer, sizeof(buffer));

    // Write the data to STDOUT (file descriptor 1).
    write(1, buffer, n);

    return 0;
}
