/**
 * The  exec() family of functions replaces the current process image with
 * a new process image.
 * The execv(), execvp(), and execvpe() functions provide an array
 * of pointers to null-terminated strings that represent the argument
 * list availabel to the new program. The first argument, by convention,
 * should point to the filename associated with the first being exected.
 * The array of pointers must be terminated by a NULL pointer.
 * */
#include <stdio.h>
#include <unistd.h>

// int execvp(const char *file, char *const argv[]);

int main()
{
    char *lsbuf[] = { "ls", "-al", NULL };

    execvp("ls", lsbuf);

      // current process has been replaced by `ls', and line
      // below won't executed any more.
    printf("### hello aaa\n");

    return 0;
}
