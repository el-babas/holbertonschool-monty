#include "monty.h"

variable_t gb_var;

/**
 * my_init - initialize global variables
 */
void my_init(void)
{
	gb_var.exit_code = EXIT_SUCCESS;
	gb_var.tokens = NULL;
	gb_var.buffer = NULL;
	gb_var.head = NULL;
	gb_var.tokenumber = 0;
	gb_var.linenumber = 1;
}

/**
 * my_main - main system logic
 * @fd_monty: identify open file monty
 */
void my_main(FILE *fd_monty)
{
	size_t sz = 0;
	ssize_t nc = 0;
	void (*f_monty)(stack_t **stack, unsigned int linenumber);

	while (nc != -1)
	{
		sz = 0;
		nc = getline(&gb_var.buffer, &sz, fd_monty);
		if (nc != -1)
		{
			my_trim(&gb_var.buffer);
			my_strtok();
			if (gb_var.tokens[0] && gb_var.tokens[0][0] != '#')
			{
				f_monty = my_getfunc(gb_var.tokens[0]);
				if (f_monty == NULL)
				{
					fprintf(stderr, "L%u: unknown instruction %s\n",
							gb_var.linenumber, gb_var.tokens[0]);
					gb_var.exit_code = EXIT_FAILURE;
				}
				else
				{
					f_monty(&gb_var.head, gb_var.linenumber);
				}
				if (gb_var.exit_code == EXIT_FAILURE)
					free(gb_var.tokens[0]);
				free(gb_var.tokens);
			}
			gb_var.linenumber++;
		}
		free(gb_var.buffer);
		if (gb_var.exit_code == EXIT_FAILURE)
			break;
	}
	my_nodefree(gb_var.head);
	if (gb_var.exit_code == EXIT_FAILURE)
		exit(gb_var.exit_code);
}

/**
 * main - project starting function
 * @argc: the number of arguments passed
 * @argv: the content of arguments passed
 * Return: EXIT_SUCCESS-> on success EXIT_FAILURE-> on error
 */
int main(int argc, char **argv)
{
	FILE *fd_monty;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd_monty = fopen(argv[1], "r");
	if (fd_monty == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	my_init();
	my_main(fd_monty);
	fclose(fd_monty);
	return (gb_var.exit_code);
}
