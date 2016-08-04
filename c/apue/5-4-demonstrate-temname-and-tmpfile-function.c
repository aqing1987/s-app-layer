#include <stdio.h>

#define MAXLINE      512

int main(int argc, char *argv[])
{
    char name[L_tmpnam], line[MAXLINE];
    FILE *fp;

    // warning: the use of `tmpnam' is dangerous
    printf("%s\n", tmpnam(NULL));

    tmpnam(name);
    printf("%s\n", name);

    if ((fp = tmpfile()) == NULL) {
        perror("tmpfile");
        return -1;
    }
    fputs("one line of output\n", fp);
    rewind(fp);
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("fgets");
        return -1;
    }
    fputs(line, stdout);

    return 0;
}
