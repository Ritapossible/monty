#include "monty.h"
/**
 * _calloc - This concatenate two strings specially.
 * @nmemb: The number of elements.
 * @size:The type of elements.
 * Return: Nothing to return.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *pt = NULL;
	unsigned int i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	pt = malloc(nmemb * size);
	if (pt == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (nmemb * size); i++)
	{
		*((char *)(pt) + i) = 0;
	}
	return (pt);
}
/**
 * _realloc - This change the size and copy the content.
 * @ptr: The malloc pointer to reallocate.
 * @old_size: The old number of bytes.
 * @new_size: The new number of Bytes.
 * Return: Nothing to return.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pt = NULL;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		pt = malloc(new_size);
		if (!pt)
			return (NULL);
		return (pt);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		pt = malloc(new_size);
		if (!pt)
			return (NULL);
		for (i = 0; i < old_size; i++)
			pt[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		p = malloc(new_size);
		if (!pt)
			return (NULL);
		for (i = 0; i < new_size; i++)
			pt[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (pt);
}
