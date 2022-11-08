#include "shell.h"

char *read_cmd(void)
{
        char *buf = NULL, *ptr = NULL;
        size_t size = 1024;
        char ptrlen = 0;

        buf = malloc(size);

        if (buf == NULL)
        {
                return (NULL);
        }

        while (getline(&buf, &size, stdin))
        {
                int buflen = 0;

                if (buf)
                {
                        while (buf[buflen])
                                buflen++;
                }

                if (!ptr)
                {
                        ptr = malloc(buflen + 1);

                        if (ptr == NULL)
                        {
                                free(buf);
                                free(ptr);
                                return (NULL);
                        }
                }
                else
                {
                        char *ptr2 = _realloc(ptr, ptrlen + buflen + 1);

                        if (ptr2)
                                ptr = ptr2;
                        else
                        {
                                free(ptr);
                                free(buf);
                                ptr = NULL;
                        }
                }
                if (!ptr)
                {
                        free(buf);
                        free(ptr);

                        printf("failed to alloc . . . \n");
                        return (NULL);
                }
		_strcpy(ptr + ptrlen, buf);

                if (buf[buflen - 1] == '\n')
                {
                        if (buflen == 1 || buf[buflen - 2] != '\\')
                        {
                                free(buf);
                                buf = NULL;
                                return (ptr);
                        }

                        buflen -= 2;
                        _puts("~$ ");
                }

                ptrlen += buflen;
        }
        buf = NULL;
        return (ptr);
}
