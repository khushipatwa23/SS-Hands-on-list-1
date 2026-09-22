// 29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).

#include <stdio.h>
#include <sched.h>

void print_policy(int policy)
{
    if (policy == SCHED_OTHER)
        printf("SCHED_OTHER\n");
    else if (policy == SCHED_FIFO)
        printf("SCHED_FIFO\n");
    else if (policy == SCHED_RR)
        printf("SCHED_RR\n");
    else
        printf("Unknown policy\n");
}

int main()
{
    int policy;
    struct sched_param param;

    policy = sched_getscheduler(0);

    if (policy == -1)
    {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current scheduling policy: ");
    print_policy(policy);

    param.sched_priority = 10;

    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1)
    {
        perror("sched_setscheduler");
        return 1;
    }

    policy = sched_getscheduler(0);

    printf("Modified scheduling policy: ");
    print_policy(policy);

    return 0;
}
