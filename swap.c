#include "monty.h"
/**
 * fn_swap - two elements addition of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void fn_swap(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(amg.file);
		free(amg.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
