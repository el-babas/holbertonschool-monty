#include "monty.h"

/**
 * my_getfunc - selects the correct function
 * @opcode: name functions
 * Return: pointer to the function that executes the opcode
 */
void (*my_getfunc(char *opcode))(stack_t **stack, unsigned int linenumber)
{
	int i;
	instruction_t f_monty[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{NULL, NULL}
	};

	for (i = 0; f_monty[i].opcode; i++)
	{
		if (my_strcmp(f_monty[i].opcode, opcode) == 0)
			break;
	}

	return (f_monty[i].f);
}
