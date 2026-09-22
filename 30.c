// 30. Write a program to run a script at a specific time using a Daemon process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    pid_t pid;
    time_t now, target;
    struct tm *t;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid > 0)
        return 0;

    setsid();

    chdir("/");

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    time(&now);
    t = localtime(&now);

    // Set the required time here
    t->tm_hour = 21;
    t->tm_min = 47;
    t->tm_sec = 0;

    target = mktime(t);

    if (target <= now)
        target += 24 * 60 * 60;

    sleep(target - now);

    system("/home/khushi/myscript.sh");

    return 0;
}
