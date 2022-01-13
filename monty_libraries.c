#include "monty.h"

/**
 * my_trim - trim string monty delimiters
 * @bf: buffer [string to trim()]
 */
void my_trim(char **bf)
{
	int i = 0, j = 0, len = 0;
	char *new_bf = NULL, *tmp_bf = *bf;

	if (**bf == ' ' || **bf == '\t')
	{
		while ((*(*bf + i) == ' ' || *(*bf + i) == '\t') && *(*bf + i) != '\0')
		{
			i++;
		}
		while (*(*bf + i + len) != '\0')
		{
			len++;
		}
		new_bf = malloc(sizeof(char) * len + 1);
		while (*(*bf + i) != '\0')
		{
			*(new_bf + j) = *(*bf + i);
			i++;
			j++;
		}
		*(new_bf + j) = '\0';
		*bf = new_bf;
		free(tmp_bf);
	}
}


/**
 * my_strtok - divide getline in tokens
 */
void my_strtok(void)
{
	int j = 0;
	char *tmp_bf;

	tmp_bf = gb_var.buffer;
	gb_var.tokens = malloc(sizeof(char *) * MAXBUFFER);
	if (!gb_var.tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		gb_var.exit_code = EXIT_FAILURE;
		return;
	}

	while ((gb_var.tokens[j] = strtok(tmp_bf, " \n\t")))
	{
		tmp_bf = NULL;
		j++;
	}
	gb_var.tokenumber = j;
}


/**
 * my_strcmp - concant two string
 * @s1: string 1
 * @s2: string 2
 * Return: INT 0=equals 0!=diferencias between s1 - s2
 */
int my_strcmp(char *s1, char *s2)
{
	int i = 0;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] == s2[i])
			continue;
		else
			return (s1[i] - s2[i]);
	}

	return (0);
}
