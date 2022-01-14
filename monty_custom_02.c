#include "monty.h"

/**
 * monty_mod - mod the top two elements of the stack.
 * @head: linked list
 * @linenumber: line number
 */
void monty_mod(stack_t **head, unsigned int linenumber)
{
	int result = my_nodemod(head);

	if (result == -1)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", linenumber);
		gb_var.exit_code = EXIT_FAILURE;
		return;
	}
	if (result == -2)
	{
		fprintf(stderr, "L%u: division by zero\n", linenumber);
		gb_var.exit_code = EXIT_FAILURE;
		return;
	}
}

/**
 * monty_pchar - print the char value of the first element..
 * @head: linked list
 * @linenumber: line number
 */
void monty_pchar(stack_t **head, unsigned int linenumber)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", linenumber);
		gb_var.exit_code = EXIT_FAILURE;
		return;
	}
	if (isascii((*head)->n) == 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", linenumber);
		gb_var.exit_code = EXIT_FAILURE;
		return;
	}
	printf("%c\n", (*head)->n);
}

/**
 * monty_pstr - print the char value of the first element..
 * @head: linked list
 * @linenumber: line number
 */
void monty_pstr(stack_t **head, unsigned int linenumber)
{
	stack_t *tmp;
	(void)linenumber;

	tmp = *head;

	while (tmp && tmp->n > 0 && tmp->n < 128)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
