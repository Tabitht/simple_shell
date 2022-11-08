#include "shell.h"

/**
 * _strcmp - compares two strings, like strcmp
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if same, negative if s1 > 2 and vice versa
 */
int _strcmp(char *s1, char *s2)
{
        int i, j, s2C = 0, c = 0;

	while (s1[c])
		c++;
	while (s2[s2C])
		s2C++;
	if (s2C == c)
	{
		for (i = 0; i < c; i++)
		{
                        if (s1[i] != s2[i])
                                return (s1[i] - s2[i]);
                        if (i == c - 1 && s1[i] == s2[i])
                                return (0);
                }
        }
        else if (s2C > c)
        {
                for (j = 0; j < c; j++)
                {
                        if (s1[j] != s2[j])
                                return (s1[j] - s2[j]);
                }
                return (-s2[c]);
        }
        else
        {
                for (j = 0; j < s2C; j++)
                {
                        if (s1[j] != s2[j])
                                return (s1[j] - s2[j]);
                }
                return (s1[s2C]);
        }
        return (0);
}

/**
 * _strcpy - copies a string
 * @dest: where to copy to
 * @src: where to copy from
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
        int c = 0, i = 0;

        while (src[c] != '\0')
                c++;

        for (i = 0; i < c; i++)
                dest[i] = src[i];

        dest[c] = '\0';

        return (dest);
}

size_t _malloc_size(void *ptr)
{
        int i = 0;
        char *a = (char *)ptr;

        while (a[i])
		i++;
	return (i);
}

/**
 * _memcpy - copies src to dest string
 * @dest: destination string
 * @src: source string
 * @n: how many bytes to copy
 *
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
        unsigned int i;

        for (i = 0; i < n; i++)
        {
                *(dest + i) = *(src + i);
        }

        return (dest);
}

/**
  *_realloc - reallocates space
  *@ptr: the ptr space
  *@size: size to be reallocated
  *
  *Return: void
  */

void *_realloc(void *ptr, size_t size)
{
        void *new;

        if (!ptr)
        {
                new = malloc(size);
                if (!new)
                {
                        return (NULL);
                }
        }
        else
        {
                if (_malloc_size(ptr) < size)
                {
                        new = malloc(size);
                        if (!new)
                        {
                                return (NULL);
                        }

                        _memcpy(new, ptr, _malloc_size(ptr));

                        free(ptr);
                }
                else
                {
                        new = ptr;
                }
        }

        return new;
}
