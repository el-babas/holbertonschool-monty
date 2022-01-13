#include "monty.h"

/**
 * my_nodefree - frees a stack_t list
 * @head: stack_t list
 */
void my_nodefree(stack_t *head)
{
	if (head != NULL)
	{
		my_nodefree(head->next);
		free(head);
	}
}


/**
 * my_nodeadd - adds a new node at the beginning of a stack_t
 * @head: stack_t
 * @n: number of node
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *my_nodeadd(stack_t **head, const int n)
{
	stack_t *new_node, *tmp_node;

	tmp_node = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = tmp_node;
	if (tmp_node != NULL)
		tmp_node->prev = new_node;
	*head = new_node;
	return (new_node);
}


/**
 * my_nodeend - adds a new node at the end of a stack_t
 * @head: stack_t list
 * @n: value
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *my_nodeend(stack_t **head, const int n)
{
	stack_t *new_node, *tmp_node;

	tmp_node = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	while (tmp_node != NULL && tmp_node->next != NULL)
		tmp_node = tmp_node->next;
	new_node->n = n;
	new_node->prev = tmp_node;
	new_node->next = NULL;
	if (tmp_node != NULL)
		tmp_node->next = new_node;
	else
		*head = new_node;
	return (new_node);
}
