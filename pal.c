#include "monty.h"

/**
 * fn_pal - stack print fn
 * @head: stack head
 * @counter: noting
 * Return: no return
*/
void fn_pal(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
