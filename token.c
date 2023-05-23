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
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || str[i + 1] == '\0'))
			numwords++;

		if (numwords == 0)
			return (NULL);

		s = malloc((numwords + 1) * sizeof(char *));
		if (!s)
			return (NULL);

		for (i = 0, j = 0; j < numwords; j++)
		{
			while (is_delim(str[i], d))
				i++;

			k = 0;
			while (!is_delim(str[i + k], d) && str[i + k] != '\0')
				k++;

			s[j] = malloc((k + 1) * sizeof(char));
			if (!s[j])
			{
				for (k = 0; k < j; k++)
				free(s[k]);
				free(s);
				return (NULL);
			}

			for (m = 0; m < k; m++)
			s[j][m] = str[i++];

			s[j][k] = '\0';
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
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	if ((str[i] != d && str[i + 1] == d) || (str[i] != d && str[i + 1] == '\0') || str[i + 1] == d)
		numwords++;

	if (numwords == 0)
		return (NULL);

	s = malloc((numwords + 1) * sizeof(char *));
	if (!s)
		return (NULL);

	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d)
			i++;

		k = 0;
		while (str[i + k] != d && str[i + k] != '\0')
			k++;

		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}

		for (m = 0; m < k; m++)
			s[j][m] = str[i++];

		s[j][k] = '\0';
	}

	s[j] = NULL;
	return (s);
}
