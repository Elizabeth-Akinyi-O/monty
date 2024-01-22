#include "monty.h"

/**
 * op_queue - sets the format of the data to a queue - FIFO
 * @stack: head of the linked list
 * @counter: line number
 *
 */
void op_queue(stack_t **stack, unsigned int counter)
{
	(void)stack;
	(void)counter;

	glob_var.lifo = 0;
}

/**
 * op_stack - sets the format for the data to a stack - LIFO
 * @stack: head of the linked list
 * @counter: line number
 *
 */
void op_stack(stack_t **stack, unsigned int counter)
{
	(void)stack;
	(void)counter;

	glob_var.lifo = 1;
}

/**
 * op_add - adds the top two elements of the stack
 * @stack: head of the linked list
 * @counter: list number
 *
 */
void op_add(stack_t **stack, unsigned int counter)
{
	int i = 0;
	stack_t *h = NULL;

	h = *stack;

	for (; h != NULL; h = h->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", counter);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	h = (*stack)->next;
	h->n += (*stack)->n;
	op_pop(stack, counter);
}

/**
 * op_nop - doesn't do anything
 * @stack: head of the linked list
 * @counter: line number
 *
 */
void op_nop(stack_t **stack, unsigned int counter)
{
	(void)stack;
	(void)counter;
}

/**
 * op_sub - subtracts the top element to the 2nd top element of the stack
 * @stack: head of the linked list
 * @counter: line number
 *
 */
void op_sub(stack_t **stack, unsigned int counter)
{
	int i = 0;

	stack_t *h = NULL;

	h = *stack;

	for (; h != NULL; h = h->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", counter);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	h = (*stack)->next;
	h->n -= (*stack)->n;
	op_pop(stack, counter);
}
