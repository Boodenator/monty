#ifndef _MONTY_H_
#define _MONTY_H_
#define  _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s, variables, args, file, line content
 * @arg: value
 * @file: ptr to file
 * @content: line content
 * @lifi: flagchange stack <-> queue
 * Description: move values through the program
 */

typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t amg;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void fn_push(stack_t **head, unsigned int number);
void fn_pal(stack_t **head, unsigned int number);
void fn_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void fn_pop(stack_t **head, unsigned int counter);
void fn_swap(stack_t **head, unsigned int counter);
void fn_addtn(stack_t **head, unsigned int counter);
void fn_nopp(stack_t **head, unsigned int counter);
void fn_subt(stack_t **head, unsigned int counter);
void fn_div(stack_t **head, unsigned int counter);
void fn_mult(stack_t **head, unsigned int counter);
void fn_modu(stack_t **head, unsigned int counter);
void fn_pchr(stack_t **head, unsigned int counter);
void fn_pstr(stack_t **head, unsigned int counter);
void fn_rotl(stack_t **head, unsigned int counter);
void fn_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnod(stack_t **head, int n);
void queaddtn(stack_t **head, int n);
void fn_que(stack_t **head, unsigned int counter);
void fn_stk(stack_t **head, unsigned int counter);

#endif
