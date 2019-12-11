#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * insert_node - Insert a node in a singed linked list
 *
 * @head: Pointer to list to add the node
 * @number: number to add to the list
 * Return: Always 0.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp;
	listint_t *new, *node;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = number;
	node = *head;
	tmp = node->next;
	if (!*head || number < node->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	while (tmp && number > tmp->n)
	{
		node = tmp;
		tmp = tmp->next;
	}
	new->next = tmp;
	node->next = new;
	return (new);
}
