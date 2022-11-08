#include "shell.h"

/**
  *main - starting point
  *
  *Return: 0 on success
  */

int main(void)
{
	char *cmd, **args;

	while (1)
	{
		_puts(":) ");
		cmd = read_cmd();

                if (cmd == NULL)
                {
                        free(cmd);
                        exit(EXIT_SUCCESS);
		}
                if (_strcmp(cmd, "exit\n") == 0)
                {
                        free(cmd);
                        break;
		}
                args = split_line(cmd);
                dash_execute(args, cmd);

                if(args)
			free(args);
		if (cmd)
			free(cmd);
        }

        return (0);
}
		
