#include "shell.h"

/**
  *dash_execute - executes the command
  *@args: the command argument
  *@cmd: the command
  *
  *Return: 1 on success
  */

int dash_execute(char **args, char *cmd)
{
	char *a[1024], *s = NULL;
	pid_t cpid;
	int status = 0, i = 0;

	memcpy(a, environ, 1024);
	if (_strcmp(args[0], "cd") == 0)
	{
		if (args[2])
			perror(": ( bash: cd: too many arguments");
		else if (args[1] && _strcmp(args[1], "-") == 0)
		{
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
			i = 0;
			s = NULL;
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
			perror(":( ");
			free(args);
			free(cmd);
		}
		exit(EXIT_FAILURE);
	}
	else if (cpid < 0)
	{
		perror("Error forking");
		free(args);
		free(cmd);
	}
	else
	{
		waitpid(cpid, &status, WUNTRACED);
	}
	return (1);
}
