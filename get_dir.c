#include "main.h"

char *get_dir(char *cmd){
    char *dir, *dir_copy, *dir_token, *file_dir;
    int cmd_length, dir_length;
    struct stat buff;

    dir = getenv("PATH");

    if (dir){
        
        dir_copy = strdup(dir);
       
        cmd_length = strlen(cmd);

        
        dir_token = strtok(dir_copy, ":");

        while(dir_token != NULL){
           
            dir_length = strlen(dir_token);
           
            file_dir = malloc(cmd_length + dir_length + 2); 
           
            strcpy(file_dir, dir_token);
            strcat(file_dir, "/");
            strcat(file_dir, cmd);
            strcat(file_dir, "\0");

            
            if (stat(file_dir, &buff) == 0){
               
                free(dir_copy);

                return (file_dir);
            }
            else{
               
                free(file_dir);
                dir_token = strtok(NULL, ":");

            }

        }

        free(dir_copy);

        if (stat(cmd, &buff) == 0)
        {
            return (cmd);
        }


        return (NULL);

    }


    return (NULL);
}
