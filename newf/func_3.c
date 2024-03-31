#include "monty.h"

/**
 * char_print - Prints the Ascii value.
 * @stack: ptr to ptr to top node of the stack.
 * @line_number: Interger f the opcode.
 */
void char_print(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, line_number);
	printf("%c\n", ascii);
}

/**
 * str_print- Prints a string.
 * @stack: ptr ot ptr to node of the stack.
 * @ln: Interger of opcode.
 */
void str_print(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}
