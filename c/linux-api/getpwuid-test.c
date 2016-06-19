#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char *argv[])
{
	char * homedir = NULL;

    homedir = getenv("HOME");
    if (homedir) {
        printf("defalut homedir(from HOME) = %s\n", homedir);
    }

    struct passwd * pw = NULL;
    pw = getpwuid(getuid());
    if (pw) {
        homedir = pw->pw_dir;
    }
    printf("my homedir = %s\n", homedir);

    pw = getpwuid(0);
    if (pw) {
        homedir = pw->pw_dir;
    }
    printf("root homedir = %s\n", homedir);

    return 0;
}
