#include "monty.h"
/**
 * fn_pop - printing top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void fn_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(amg.file);
		free(amg.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
