#include <stdio.h>
#include <unistd.h>

int main() {
    if (link("orig.txt", "hardlink2.txt") == -1) {
        perror("link");
        return 1;
    }

    printf("Hard link created successfully.\n");

    return 0;
}
