#include "monty.h"
/**
 * fn_modu - calculates the remainder
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void fn_modu(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(amg.file);
		free(amg.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(amg.file);
		free(amg.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
