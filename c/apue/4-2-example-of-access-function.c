/**
 * test cases:
 * $ ls -l a.out
 * -rwxrwxr-x 1
 * $ ./a.out a.out
 * read access ok
 * open for reading ok
 * $ ls -l /etc/shadow
 * -rw-r----- 1 root shadow
 * $ ./a.out /etc/shadow
 * access: Permission denied
 * open: Permission denied
 * $ sudo chown root:root a.out # change file's user ID to root
 * $ sudo chmod u+s a.out # and turn on set-user-ID bit
 * $ ls -l a.out # check owner and SUID bit
 * -rwsrwxr-x 1 root root
 * $ ./a.out /etc/shadow
 * access: Permission denied
 * open for reading ok
 * the set-user-ID program can determine that the real user cannot normally
 * read the file, even though the open function will succeed.
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: %s <pathname>\n", argv[0]);
        return -1;
    }

    // int access(const char *pathname, int mode);
    if (access(argv[1], R_OK) < 0) {
        perror("access");
    } else {
        printf("read access ok\n");
    }

    if (open(argv[1], O_RDONLY) < 0) {
        perror("open");
    } else {
        printf("open for reading ok\n");
    }

    return 0;
}
