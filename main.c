#include "main.h"

int main(int tc, char **argv)
{
    char *prompt = "(Tshell) $ ";
    char *lineptr = NULL, *lineptr_cpy = NULL;
    const char *delimiter = " \n";
    size_t t = 0;
    ssize_t read_nchars;
    int num_tokens = 0;
    char *token;
    int i;

    /* declaring void variables for the tc and argv */  
    (void)tc;

    /* creating an infinite loop */
    while (1)
    {
        printf("%s", prompt);
        read_nchars = getline(&lineptr, &t, stdin);
        /* check if user use ctr + c or the function failed or reached EOF */
        if (read_nchars == -1)
        {
            printf("Existing Tshell......\n");
            return (-1);
        }

        /* space allocation for copy of the line pointer */
        lineptr_cpy = malloc(sizeof(char) * read_nchars);
        if (lineptr_cpy== NULL)
        {
            perror("tsh: error in memory allocation");
            return (-1);
        }

        /* copying lineptr to lineptr_copy */
        strcpy(lineptr_cpy, lineptr);

        /*split the string (lineptr) into an array of words */
        /* calculate the total number of tokens */
        token = strtok(lineptr, delimiter);

        while (token != NULL)
        {
            num_tokens++;
            token = strtok(NULL, delimiter);
        }
        num_tokens++;

        /* Allocate space to hold the array of strings */
        argv = malloc(sizeof(char *) * num_tokens);

        /* Store each token in the argv array */
        token = strtok(lineptr_cpy, delimiter);

        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delimiter);
        }
        argv[i] = NULL;

        /* execute the command */
        execmd(argv);

    } 


    /* free up allocated memory */ 
    free(lineptr_cpy);
    free(lineptr);

    return (0);
}