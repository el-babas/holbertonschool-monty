#include "monty.h"

/**
 * my_nodemod - mod the top two elements of the stack
 * @head: list
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int my_nodemod(stack_t **head)
{
	int count = 0;
	stack_t *tmp = NULL;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	if (count < 2)
		return (-1);
	if ((*head)->n == 0)
		return (-2);
	tmp = (*head)->next;
	tmp->n %= (*head)->n;
	return (my_nodedel(head, 0));
}
