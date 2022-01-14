#include "monty.h"

/**
 * monty_add - adds the top two elements of the stack. (sum)
 * @head: linked list
 * @linenumber: line number
 */
void monty_add(stack_t **head, unsigned int linenumber)
{
	if (my_nodesum(head) != 1)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", linenumber);
		gb_var.exit_code = EXIT_FAILURE;
		return;
	}
}

/**
 * monty_sub - adds the top two elements of the stack. (resta)
 * @head: linked list
 * @linenumber: line number
 */
void monty_sub(stack_t **head, unsigned int linenumber)
{
	if (my_nodesub(head) != 1)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", linenumber);
		gb_var.exit_code = EXIT_FAILURE;
		return;
	}
}

/**
 * monty_div - divide the top two elements of the stack.
 * @head: linked list
 * @linenumber: line number
 */
void monty_div(stack_t **head, unsigned int linenumber)
{
	int result = my_nodediv(head);

	if (result == -1)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", linenumber);
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
 * monty_mul - multiplique the top two elements of the stack.
 * @head: linked list
 * @linenumber: line number
 */
void monty_mul(stack_t **head, unsigned int linenumber)
{
	if (my_nodemul(head) != 1)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", linenumber);
		gb_var.exit_code = EXIT_FAILURE;
		return;
	}
}

/**
 * monty_nop - doesn’t do anything.
 * @head: linked list
 * @linenumber: line number
 */
void monty_nop(stack_t **head, unsigned int linenumber)
{
	(void)head;
	(void)linenumber;
}
