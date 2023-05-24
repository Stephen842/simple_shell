#include "shell.h"
/**
 * **strtow - this function count the number of word in the poput string by
 * iterating through it
 * @str: function parameter showing the input string
 * @d: function parameter showing d as a delimeter string
 * Return: 0 if successful
 */
char **strtow(char *str, char *d)
{
	int a;
	int j;
	int e;
	int m;
	int numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);

	s = malloc((numwords + 1) * sizeof(char *));
	if (!s)
		return (NULL);

	for (a = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[a], d))
			a++;

		e = 0;
		while (!is_delim(str[a + e], d) && str[a + e] != '\0')
			e++;

		s[j] = malloc((e + 1) * sizeof(char));
		if (!s[j])
		{
			for (e = 0; e < j; e++)
				free(s[e]);
			free(s);
			return (NULL);
		}

		for (m = 0; m < e; m++)
			s[j][m] = str[a++];
		s[j][m] = 0;
	}

	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - this function has similar function but uses a single char as a
 * delimiter instead of a delimiter string
 * @str: function parameter showing the input string
 * @d: funnction parameter indicating the delimeter
 * Return: 0 if successful
 */
char **strtow2(char *str, char d)
{
	int a;
	int j;
	int f;
	int e;
	int numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);

	for (a = 0; str[a] != '\0'; a++)
	if ((str[a] != d && str[a + 1] == d) || (str[a] != d && !str[a + 1]) || str[a + 1] == d)
		numwords++;

	if (numwords == 0)
		return (NULL);

	s = malloc((numwords + 1) * sizeof(char *));
	if (!s)
		return (NULL);

	for (a = 0, j = 0; j < numwords; j++)
	{
		while (str[a] == d && str[a] != d)
			a++;

		f = 0;
		while (str[a + f] != d && str[a + f] && str[a + f] != d)
			f++;

		s[j] = malloc((f + 1) * sizeof(char));
		if (!s[j])
		{
			for (f = 0; f < j; f++)
				free(s[f]);
			free(s);
			return (NULL);
		}

		for (e = 0; e < f; e++)
			s[j][e] = str[a++];

		s[j][e] = 0;
	}

	s[j] = NULL;
	return (s);
}
