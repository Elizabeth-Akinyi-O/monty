#include "monty'h"
/**
 * _calloc - concatenates two strings
 * @num: number of elements
 * @size: type of elements
 *
 * Return: nothing
 */
void *_calloc(unsigned int num, unsigned int size)
{
	void *p = NULL;
	unsigned int a;

	if (num == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(num * size);
	if (p == NULL)
	{
		return (NULL);
	}

	for (a = 0; a < (num * size); a++)
	{
		*((char *)(p) + a) = 0;
	}
	return (p);
}

/**
 * _realloc - changes the size and copies the content
 * @ptr: pointer to be reallocated
 * @size_old: old number of bytes
 * @size_new: new number of bytes
 *
 * Return: nothing
 */
void *_realloc(void *ptr, unsigned int size_old, unsigned int size_new)
{
	char *p = NULL;
	unsigned int b;

	if (size_new == size_old)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(size_new);
		if (!p)
			return (NULL);
		return (p);
	}
	if (size_new == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (size_new > size_old)
	{
		p = malloc(size_new);
		if (!p)
			return (NULL);
		for (b = 0; b < size_old; b++)
			p[b] = *((char *)ptr + b);
		free(ptr);
	}
	else
	{
		p = malloc(size_new);
		if (!p)
			return (NULL);
		for (b = 0; b < size_new; b++)
			p[b] = *((char *)ptr + b);
		free(ptr);
	}
	return (p);
}
