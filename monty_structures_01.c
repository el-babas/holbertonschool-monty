#include "monty.h"

/**
 * my_nodesum - sum the top two elements of the stack
 * @head: list
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int my_nodesum(stack_t **head)
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
	tmp = (*head)->next;
	tmp->n += (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	return (1);
}
