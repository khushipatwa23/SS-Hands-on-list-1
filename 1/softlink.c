#include <stdio.h>
#include <unistd.h>

int main() {
    if (symlink("orig.txt", "softlink2.txt") == -1) {
        perror("symlink");
        return 1;
    }

    printf("Soft link created successfully.\n");

    return 0;
}

