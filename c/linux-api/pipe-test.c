/**
 * pipe()  creates  a pipe, a unidirectional data channel that can be used
 * for interprocess communication.  The array pipefd is used to return two
 * file  descriptors  referring to the ends of the pipe.
 * pipefd[0] refers to the read end of the pipe. pipefd[1] refers to the
 * write end of the pipe. Data written to the write end of the pipe is
 * buffered by the kernel until it is read from the read end of the pipe.
 * */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int pipefd[2];
	pid_t pid;
    char rbuf[1024] = "";

        //char *scrip[] = { "/etc/rc.d/S96blacklist", "reload", NULL };
    char *scrip[] = { "ls", "/tmp", NULL };

	if (pipe(pipefd) == -1) {
        perror("pipe");
		return -1;
	}

	pid = fork();
	if (pid < 0) {
        perror("fork");
		return -1;
    }

	if (pid) { // parent
		close(pipefd[1]); // close unused write end
        read(pipefd[0], rbuf, sizeof(rbuf));
        printf("get from child process - \n%s\n", rbuf);
        close(pipefd[0]);

        return -1;
	}
    else { // child process
        close(pipefd[0]); // close unused read end
        printf("child before dup2\n");

        // redirect stderr, stdout to write end
        dup2(pipefd[1], STDOUT_FILENO);
        dup2(pipefd[1], STDERR_FILENO);

        execlp(scrip[0], scrip[0], scrip[1], NULL);
        exit(1);
    }

    return 0;
}


