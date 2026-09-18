// This program opens a file in read-only mode,
// reads it line by line, displays each line,
// and closes the file when EOF is reached.

#include <stdio.h>

int main()
{
    FILE *fp;
    char line[100];

    fp = fopen("file1", "r");

    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line);
    }

    fclose(fp);

    return 0;
}
