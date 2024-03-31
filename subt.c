#include "monty.h"
/**
  *fn_subt: subtraction of two elements
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void fn_subt(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sub, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(amg.file);
		free(amg.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sub = aux->next->n - aux->n;
	aux->next->n = sub;
	*head = aux->next;
	free(aux);
}
