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
 * monty_nop - doesn’t do anything.
 * @head: linked list
 * @linenumber: line number
 */
void monty_nop(stack_t **head, unsigned int linenumber)
{
	(void)head;
	(void)linenumber;
}
