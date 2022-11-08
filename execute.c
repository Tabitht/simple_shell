#include "shell.h"

int dash_execute(char **args, char *cmd)
{
        char *a[1024];
        pid_t cpid;
        int status = 0;
        memcpy(a, environ, 1024);

        if (_strcmp(args[0], "cd") == 0)
        {
                if (args[2])
                        perror(": ( ");//printf("bash: cd: too many arguments\n");
                else if (args[1] && _strcmp(args[1], "-") == 0)
                {
                        int i = 0;
                        char *s = NULL;
                        while (environ[i])
                        {
                                s = strtok(strdup(environ[i]), "=");
                                if (strcmp(s, "OLDPWD") == 0)                
				{
                                        chdir(strtok(NULL, "="));
                                        break;
                                }
                                i++;
                        }
                }
                else if (!args[1])
                {
                        int i = 0;
                        char *s = NULL;
                        while (environ[i])
                        {
                                s = strtok(strdup(environ[i]), "=");
                                if (strcmp(s, "HOME") == 0)
                                {
                                        chdir(strtok(NULL, "="));
                                        break;
				}
				i++;
                        }
                }
                else
                        chdir(args[1]);

                args = NULL;
        }

        cpid = fork();
        if (cpid == 0)
        {
                if (execvp(args[0], args) < 0)
                {
                        perror(":( ");//printf("dash: command not found: %s\n args[0]);
                        free(args);
                        free(cmd);
                }

                exit(EXIT_FAILURE);
        }
	else if (cpid < 0)
        {
                printf("Error forking\n");
                free(args);
                free(cmd);
        }
        else
        {
                waitpid(cpid, &status, WUNTRACED);
        }
        /*if (execvp(args[0], args) < 0)
        {                                                                                         printf("dash: command not found: %s\n", args[0]);
                free(args);
                free(cmd);
        }*/
        return (1);
}
