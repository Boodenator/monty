#include "monty.h"

/**
 * f_pall - prints stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	 if (h == NULL)
                return;
}
