#include "monty.h"
/**
 * f_queue - prints the top
 * @head: head of stck
 * @counter: line_number
 * Return: no return
*/
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	pol.lifi = 1;
}

/**
 * addqueue - add node to stck tail
 * @n: new_value
 * @head: stck head
 * Return: no return
*/
void addqueue(stack_t **head, int n)
{
	stack_t *n_node, *aux;

	aux = *head;
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		printf("Error\n");
	}
	n_node->n = n;
	n_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = n_node;
		n_node->prev = NULL;
	}
	else
	{
		aux->next = n_node;
		n_node->prev = aux;
	}
}
