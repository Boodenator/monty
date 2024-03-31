#include "monty.h"
/**
 * fn_mult - multiplication of elements.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void fn_mult(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int dig = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		dig++;
	}
	if (dig < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
