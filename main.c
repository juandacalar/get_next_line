#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY); // Replace "test.txt" with the path to your test file

    if (fd == -1)
    {
        printf("Failed to open the file.\n");
        return 1;
    }

    char *line;
    int line_count = 1;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s\n", line_count, line);
        free(line);
        line_count++;
    }

    printf("Reached end of file.\n");

    close(fd);

    return 0;
}