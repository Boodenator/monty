#include "monty.h"

/**
 * mul_nodes - Adds the top two elements of the stack.
 * @stack: Ptr to ptr to top node of the stack.
 * @line_number: represent the line number of of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int n_sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	n_sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = n_sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - Adds the top two elements of the stack.
 * @stack: ptr to ptr to top node of the stack.
 * @line_number: Interger of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int n_sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	n_sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = n_sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
