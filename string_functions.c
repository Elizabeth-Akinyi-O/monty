#include "monty.h"

/**
 * _strcmpp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if s1 and s2 are equal or another value if they are not
 */
int _strcmpp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] == s2[a] && s1[a]; a++)
		;

	if (s1[a] > s2[a])
		return (1);
	if (s1[a] < s2[a])
		return (-1);
	return (0);
}

/**
 * _sch - searches if a character is inside a string
 * @s: string
 * @c: character to be found
 *
 * Return: 1 on success, 0 if not
 */
int _sch(char *s, char c)
{
	int i = 0; /* iterator */

	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			break;
		}
		i++;
	}
	if (s[i] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtokk - tokenizes a string
 * @s: string input
 * @delim: delimiter
 *
 * Return: token
 */
char *_strtokk(char *s, char *delim)
{
	static char *stok;

	int a = 0;
	int b = 0;

	if (!s)
		s = stok;
	while (s[a] != '\0')
	{
		if (_sch(delim, s[a]) == 0 && s[a + 1] == '\0')
		{
			stok = s + a + 1;
			*stok = '\0';
			s = s + b;
			return (s);
		}
		else if (_sch(delim, s[a]) == 0 && s(delim, s[a + 1]) == 0)
			a++;
		else if (_sch(delim, s[a]) == 0 && s(delim, s[a + 1]) == 1)
		{
			stok = s + a + 1;
			*stok = '\0';
			stok++;
			s = s + b;
			return (s);
		}
		else if (_sch(delim, s[a]) == 1)
		{
			b++;
			a++;
		}
	}
	return (NULL);
}
