#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Ptr to ptr pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @stack: Ptr to pte to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *etmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	temp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Ptr to ptr to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int n_sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	n_sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = n_sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes - Adds the top two elements of the stack.
 * @stack: Ptr to ptr top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int n_sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	n_sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = n_sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: Ptr to ptr totop node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int n_sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	n_sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = n_sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
