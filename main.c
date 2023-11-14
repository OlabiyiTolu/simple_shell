# include "main.h"

int main(int tc, char **argv){
    char *prompt = "(Tshell) $ ";
    char *lineptr;
    size_t t = 0;

    /* declaring void variables for the tc and argv */
    (void)tc; (void)argv;

    /* creating an infinite loop */
    while (1){
        printf("%s", prompt);
        getline(&lineptr, &t, stdin);
        printf("%s\n", lineptr);

        /* code to free memory*/
        free(lineptr);
    }

    
    return (0);
}