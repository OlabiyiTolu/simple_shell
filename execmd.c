#include "main.h"

void execmd(char **argv) {
    char *cmd = NULL, *actual_cmd = NULL;

    if (argv) {
        /* get the command */
        cmd = argv[0];

        /* generate the path to this command before passing it to execve */
        actual_cmd = get_dir(cmd);

        /* execute the actual command with execve */
        if (execve(actual_cmd, (const char * const *)argv, NULL) == -1) {
            perror("Error:");
        }
    }
}
