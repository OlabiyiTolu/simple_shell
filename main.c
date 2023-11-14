#include "main.h"

int main(int tc, char **argv){
    char *prompt = "(Tshell) $ ";
    char *lineptr;
    size_t t = 0;
    ssize_t read_nchars;

    /* declaring void variables for the tc and argv */
    (void)tc; (void)argv;

    /* creating an infinite loop */
    while (1){
        printf("%s", prompt);
        read_nchars = getline(&lineptr, &t, stdin);
        /* check if user use ctr + c or the function failed or reached EOF */
            if (read_nchars == -1){
                printf("Existing tshell......\n");
                return (-1);
        }

        printf("%s\n", lineptr);

        /* code to free memory*/
        free(lineptr);
    }
    
    return (0);
}