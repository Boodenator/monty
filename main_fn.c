#include "monty.h"

/**
* execute - opcode execution
* @stack: linked list head - stack
* @counter: line_counter
* @file: ptr to file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", fn_push}, {"pall", fn_pal}, {"pint", fn_pint},
				{"pop", fn_pop},
				{"swap", fn_swap},
				{"add", fn_addtn},
				{"nop", fn_nopp},
				{"sub", fn_subt},
				{"div", fn_div},
				{"mul", fn_mult},
				{"mod", fn_modu},
				{"pchar", fn_pchr},
				{"pstr", fn_pstr},
				{"rotl", fn_rotl},
				{"rotr", fn_rotr},
				{"queue", fn_que},
				{"stack", fn_stk},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

/**
 * addnod - stack node addition
 * @head: stack head
 * @n: new_value
 * Return: no return
*/
void addnod(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
* free_stack - free dbly lnked list
* @head: stack head
*/
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
