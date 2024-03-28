#include "monty.h"
/**
  *f_rotr- rotates stck toward bottom
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev = NULL;
	copy->prev->next = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
