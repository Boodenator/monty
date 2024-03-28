#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: the stack head
 * @counter: the line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (pol.arg)
	{
		if (pol.arg[0] == '-')
			j++;
		for (; pol.arg[j] != '\0'; j++)
		{
			if (pol.arg[j] > 57 || pol.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(pol.file);
			free(pol.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(pol.file);
		free(pol.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(pol.arg);
	if (pol.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
