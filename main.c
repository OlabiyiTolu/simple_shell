# include "main.h"

int main(int tc, char **argv){
    char *prompt = "(Tshell) $ ";
    char *lineptr;
    size_t t = 0;

    /* declaring void variables */
    (void)tc; (void)argv;

    printf("%s", prompt);
    getline(&lineptr, &t, stdin);
    printf("%s\n", lineptr);

    free(lineptr);
    return (0);
}