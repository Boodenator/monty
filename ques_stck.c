#include "monty.h"
/**
 * fn_que - print top of stck
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void fn_que(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * queaddtn - node addition to tail stack
 * @n: new_value
 * @head: stack head
 * Return: no return
*/
void queaddtn(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}

/**
 * fn_stk - top print
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void fn_stk(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
