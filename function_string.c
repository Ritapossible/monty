#include "monty.h"

/**
 * _strcmp - The function that compares two strings.
 * @n1: The type string compared.
 * @n2: The type string compared.
 * Return: Always 0 if n1 and n2 are equals.
 *         another value if they are different.
 */
int _strcmp(char *n1, char *n2)
{
int i;

for (i = 0; n1[i] == n2[i] && n1[i]; i++)
	;
if (n1[i] > n2[i])
return (1);
if (n1[i] < n2[i])
return (-1);
return (0);
}

/**
 * _sch - This search if a char is inside a string.
 * @n: The string to be reviewed.
 * @s: The char to find.
 * Return: Always 1 if success 0 if not.
 */
int _sch(char *n, char s)
{
int count = 0;
while (n[count] != '\0')
{
if (n[count] == s)
{
break;
}
count++;
}
if (n[count] == s)
return (1);
else
return (0);
}

/**
 * _strtoky - The function that cut a string into tokens
 *  depending of the delimit.
 * @s: The string to cut in parts.
 * @d: The delimiters.
 * Return: First partition.
 */
char *_strtoky(char *s, char *d)
{
static char *ultimo;
int x = 0, y = 0;
if (!s)

s = ultimo;
while (s[x] != '\0')
{
if (_sch(d, s[x]) == 0 && s[x + 1] == '\0')
{
ultimo = s + x + 1;
*ultimo = '\0';
s = s + y;
return (s);
}
else if (_sch(d, s[x]) == 0 && _sch(d, s[x + 1]) == 0)
x++;
else if (_sch(d, s[x]) == 0 && _sch(d, s[x + 1]) == 1)
{
ultimo = s + x + 1;
*ultimo = '\0';
ultimo++;
s = s + y;
return (s);
}
else if (_sch(d, s[x]) == 1)
{
y++;
x++;
}
}
return (NULL);
}
