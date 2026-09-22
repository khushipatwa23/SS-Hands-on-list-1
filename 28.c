// 28. Write a program to get maximum and minimum real time priority.

#include <stdio.h>
#include <sched.h>

int main()
{
    int max_priority;
    int min_priority;

    max_priority = sched_get_priority_max(SCHED_FIFO);
    min_priority = sched_get_priority_min(SCHED_FIFO);

    if (max_priority == -1 || min_priority == -1)
    {
        perror("sched_get_priority");
        return 1;
    }

    printf("Maximum real-time priority: %d\n", max_priority);
    printf("Minimum real-time priority: %d\n", min_priority);

    return 0;
}
