#include "monty.h"

/**
 * monty_push - push element to the stack
 * @head: linked list
 * @linenumber: line number
 */
void monty_push(stack_t **head, unsigned int linenumber)
{
	int n, i;

	if (gb_var.tokenumber < 2)
	{
		fprintf(stderr, "L%d: usage: push integer\n", linenumber);
		gb_var.exit_code = EXIT_FAILURE;
		return;
	}
	for (i = 0; gb_var.tokens[1][i] != '\0'; i++)
	{
		if (!isdigit(gb_var.tokens[1][i]) && gb_var.tokens[1][i] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", linenumber);
			gb_var.exit_code = EXIT_FAILURE;
			return;
		}
	}
	n = atoi(gb_var.tokens[1]);
	if (my_nodeadd(head, n) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		gb_var.exit_code = EXIT_FAILURE;
		return;
	}
}


/**
 * monty_pall - prints all values to the stack
 * @head: linked list
 * @linenumber: line number
 */
void monty_pall(stack_t **head, unsigned int linenumber)
{
	stack_t *tmp;
	(void)linenumber;

	tmp = *head;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * monty_pint - prints the value at the top of the stack
 * @head: linked list
 * @linenumber: line number
 */
void monty_pint(stack_t **head, unsigned int linenumber)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", linenumber);
		gb_var.exit_code = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*head)->n);
}

/**
 * monty_pop - removes the top element of the stack.
 * @head: linked list
 * @linenumber: line number
 */
void monty_pop(stack_t **head, unsigned int linenumber)
{
	if (my_nodedel(head, 0) != 1)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", linenumber);
		gb_var.exit_code = EXIT_FAILURE;
		return;
	}
}
