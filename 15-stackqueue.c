#include "monty.h"
/**
 * f_queue - print the top
 * @head: stck head
 * @counter: line_number
 * Return: no return
*/
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	var.lifi = 1;
}
/**
 * f_stack - print top
 * @head: stck head
 * @counter: line_number
 * Return: no return
*/
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	var.lifi = 0;
}
/**
 * addqueue - add node to stack end
 * @n: new_value
 * @head: stack head
 * Return: no return
*/
void addqueue(stack_t **head, int n)
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
	if (!aux)
        {
                *head = new_node;
                new_node->prev = NULL;
        }
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
