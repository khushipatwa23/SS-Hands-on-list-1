// This program measures the CPU cycles taken by the getpid() system call.

#include <stdio.h>
#include <unistd.h>

static inline unsigned long long rdtsc()
{
    unsigned int low, high;

    __asm__ volatile (
        "rdtsc"
        : "=a"(low), "=d"(high)
    );

    return ((unsigned long long)high << 32) | low;
}

int main()
{
    unsigned long long start, end;
    pid_t pid;

    start = rdtsc();

    pid = getpid();

    end = rdtsc();

    printf("PID: %d\n", pid);
    printf("CPU cycles taken by getpid(): %llu\n", end - start);

    return 0;
}
