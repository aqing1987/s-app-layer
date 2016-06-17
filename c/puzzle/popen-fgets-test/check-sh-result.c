#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INVOKE_SCRIPT_CMD "./sync-s"

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
	char str[256] = "";
    char cmd[256] = "";

    fp = popen(INVOKE_SCRIPT_CMD, "r");
	if (fp) {
		fgets(str, sizeof(str), fp);
		pclose(fp);

        str[255] = '\0';
		printf("### script output : %s\n", str);

        sprintf(cmd, "echo \"### scripts output: %s\" > /tmp/bbbb", str);
        system(cmd);

	} else {
        printf("popen error!\n");
	}

    return 0;
}
