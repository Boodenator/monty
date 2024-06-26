#include "monty.h"
/**
 * fn_pint - print the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void fn_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(amg.file);
		free(amg.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
