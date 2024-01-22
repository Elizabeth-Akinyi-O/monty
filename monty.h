#ifndef _MONTY_
#define _MONTY_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
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
 * struct global_stru - global structure
 * @lifo: is a stack or queue
 * @l_cont: line comntent
 * @arg: 2nd parameter inside the the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buff: input text
 *
 * Description: DLL node structure for stack,
 * queues, LIFO, FIFO - Alx (Holberton) Project
 */
typedef struct global_stru
{
	int lifo;
	unsigned int l_cont;
	char *arg;
	stack_t *head;
	FILE *fd;
	char *buff;
} global_t;
extern global_t glob_var;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t glob_var;

/* all opcode functions */
void op_push(stack_t **stack, unsigned int counter);
void op_pall(stack_t **stack, unsigned int counter);
void op_pint(stack_t **stack, unsigned int counter);
void op_pop(stack_t **stack, unsigned int counter);
void op_swap(stack_t **stack, unsigned int counter);
void op_queue(stack_t **stack, unsigned int counter);
void op_stack(stack_t **stack, unsigned int counter);
void op_add(stack_t **stack, unsigned int counter);
void op_nop(stack_t **stack, unsigned int counter);
void op_sub(stack_t **stack, unsigned int counter);
void op_div(stack_t **stack, unsigned int counter);
void op_mul(stack_t **stack, unsigned int counter);
void op_mod(stack_t **stack, unsigned int counter);
void op_pchar(stack_t **stack, unsigned int counter);
void op_pstr(stack_t **stack, unsigned int counter);
void op_rotl(stack_t **stack, unsigned int counter);
void op_rotr(stack_t **stack, unsigned int counter);

/* get function */
void (*exec_opcode(char *opc))(stack_t **stack, unsigned int line_number);

/* string functions */
int _strcmpp(char *s1, char *s2);
int _sch(char *s, char c);
char *_strtokk(char *s, char *delim);

/* stack functions */
stack_t *add_node_beg(stack_t **head, const int n);
stack_t *add_node_end(stack_t **head, const int n);
void free_nodes(stack_t *head);

/* malloc functions */
void *_calloc(unsigned int num, unsigned int size);
void *_realloc(void *ptr, unsigned int size_old, unsigned int size_new);

/* main */
void free_glob_var(void);

#endif
