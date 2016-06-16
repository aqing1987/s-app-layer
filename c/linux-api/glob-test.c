/**
 * @file   glob-test.c
 * @brief  test glob api
 *
 * int glob(const char *pattern, int flags,
 *               int (*errfunc) (const char *epath, int eerrno),
 *               glob_t *pglob);
 * The glob() function searches for all  the  pathnames  matching  pattern
 *      according  to  the  rules  used  by  the shell
 * The results of a glob() call are stored in the structure pointed to  by
 *      pglob.
 * On  successful completion, glob() returns zero.
 *
 * @author re-x
 * @date   2016-06-16
 */
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <glob.h>

int main()
{
    int j;

    char globdir[256] = "./*";
	glob_t gl;

    // GLOB_ONLYDIR - the caller is interested only in directories that
    //                match the pattern.
    // GLOB_MARK - Append a slash to each path which corresponds to a directory
    // GLOB_NOESCAPE - Don't  allow  backslash ('\') to be used as an
    //                 escape character.
    // typedef struct {
    //           size_t   gl_pathc;    /* Count of paths matched so far  */
    //           char   **gl_pathv;    /* List of matched pathnames.  */
    //           size_t   gl_offs;     /* Slots to reserve in gl_pathv.  */
    //       } glob_t;
    // cannot find the hidden directory (. directory) by using code below
	if (!glob(globdir, GLOB_NOESCAPE | GLOB_MARK | GLOB_ONLYDIR, NULL, &gl)) {
        for (j = 0; j < gl.gl_pathc; j++) {
            printf("dir[%d] - %s\n", j, gl.gl_pathv[j]);    
        }
    }

    return 0;
}
