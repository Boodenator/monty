#include "monty.h"
/**
  *fn_rotl- to top rotation
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void fn_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tpr = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tpr->next != NULL)
	{
		tpr = tpr->next;
	}
	tpr->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tpr;
	(*head) = aux;
}
