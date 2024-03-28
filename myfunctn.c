#include "monty.h"

/**
* execute - opcode exectution
* @stack: head lnked list - stack
* @counter: line_counter
* @file: ptr to monty
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	var.arg = strtok(NULL, " \n\t");
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
 * addnode - add new node to head
 * @head: stack head
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **head, int n)
{

	stack_t *nw_nod, *aux;

	aux = *head;
	nw_nod = malloc(sizeof(stack_t));
	if (nw_nod == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = nw_nod;
	nw_nod->n = n;
	nw_nod->next = *head;
	nw_nod->prev = NULL;
	*head = nw_nod;
}

/**
* free_stack -> frees dbly lnked list
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
