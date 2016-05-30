// ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("/tmp/hh", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

      // len is alloced buffer size
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("alloced %zu, line length(%zu):\n", len, read);
        printf("%s", line);
    }

    free(line);
    fclose(fp);

    return 0;
}
