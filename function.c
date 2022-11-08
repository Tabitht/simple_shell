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
	int i, diff = 0;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			break;
			return (diff);
		}
		else if (s1[i] == s2[i])
			diff = 0;
	}
	return (diff);
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

/**
  *_malloc_size - size of malloc
  *@ptr: the ptr
  *
  *Return: size_t
  */

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
	return (new);
}
