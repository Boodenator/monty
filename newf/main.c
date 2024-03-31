#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments no
 * @argv: arguments list
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - make new node.
 * @n: Number to go inside the node.
 * Return: if sucess ptr to the node. else NULL.
 */
stack_t *create_node(int n)
{
	stack_t *new_nnode;

	new_nnode = malloc(sizeof(stack_t));
	if (new_nnode == NULL)
		err(4);
	new_nnode->next = NULL;
	new_nnode->prev = NULL;
	new_nnode->n = n;
	return (new_nnode);
}

/**
 * free_nodes - Free the nodes at stack.
 */
void free_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * add_to_queue - Adds new node to quee.
 * @new_node: Ptr to new node.
 * @ln: line number of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;

}
