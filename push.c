#include "monty.h"

/**
 * fn_push - push new node 
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void fn_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (amg.arg)
	{
		if (amg.arg[0] == '-')
			j++;
		for (; amg.arg[j] != '\0'; j++)
		{
			if (amg.arg[j] > 57 || amg.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(amg.file);
			free(amg.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(amg.file);
		free(amg.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(amg.arg);
	if (amg.lifi == 0)
		addnod(head, n);
	else
		queaddtn(head, n);
}
