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

/**
 * my_nodedel - deletes the node at index index of a dlistint_t
 * @head: list
 * @index: position insert
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int my_nodedel(stack_t **head, unsigned int index)
{
	stack_t *tmp = *head;

	if (tmp == NULL)
		return (-1);
	if (index == 0)
	{
		*head = tmp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		while (tmp != NULL)
		{
			if (index == 0)
				break;
			index--;
			tmp = tmp->next;
		}
		/* if it is not possible deleted the node */
		if (tmp == NULL && index != 1)
			return (-1);
		tmp->prev->next = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = tmp->prev;
	}
	free(tmp);
	return (1);
}

/**
 * my_nodeswp - swaps the top two elements of the stack
 * @head: list
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int my_nodeswp(stack_t **head)
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

	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	tmp->prev = *head;
	(*head)->next = tmp;
	(*head)->prev = NULL;
	return (1);
}
