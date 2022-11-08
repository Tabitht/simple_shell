#include "shell.h"

char **split_line(char *line)
{
        int buffsize = 1024, position = 0;
        char *TOK_DELIM = " \t\r\n";
        int TK_BUFF_SIZE = 1024;
        char *token;
        char **tokens = NULL;

        tokens = malloc(buffsize * sizeof(char *));

        if (!tokens)
        {
                free(tokens);
                printf("allocation error\n");
                exit(EXIT_FAILURE);
        }

        token = strtok(line, TOK_DELIM);

        if (token == NULL)                                                  
	{
                free(token);
                exit (EXIT_FAILURE);
        }

        while (token != NULL)
        {
                tokens[position] = token;
                position++;

                if (position >= buffsize)
                {
                        buffsize += TK_BUFF_SIZE;
                        tokens = _realloc(tokens, buffsize * sizeof(char *));

                        if (!tokens)
                        {
                                free(tokens);
                                printf("allocation error\n");
                                exit(EXIT_FAILURE);
                        }
                }

                token = strtok(NULL, TOK_DELIM);
        }

        tokens[position] = NULL;

        return tokens;
}
