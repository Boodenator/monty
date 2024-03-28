#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (var.arg)
	{
		if (var.arg[0] == '-')
			j++;
		for (; var.arg[j] != '\0'; j++)
		{
			if (var.arg[j] > 57 || var.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(var.file);
			free(var.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(var.file);
		free(var.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(var.arg);
	if (var.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
