#include "monty.h"

/**
 * op_rotl - rotates the stack to the top - The top element of
 * the stack becomes the last one, and the second top
 * element of the stack becomes the first one
 * @stack: head of the linked list
 * @counter: line number
 *
 */
void op_rotl(stack_t **stack, unsigned int counter)
{
	stack_t *h1 = NULL;
	stack_t *h2 = NULL;
	(void)counter;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	h1 = (*stack)->next;
	h2 = *stack;

	for (; h2->next != NULL; h2 = h2->next)
		;

	h1->prev = NULL;
	h2->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = h2;
	*stack = h1;
}

/**
 * op_rotr - rotates the stack to the bottom - The last
 * element of the stack becomes the top element of the stack
 * @stack: head of the linked list
 * @counter: line number
 *
 */
void op_rotr(stack_t **stack, unsigned int counter)
{
	stack_t *h = NULL;
	(void)counter;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	h = *stack;

	for (; h->next != NULL; h = h->next)
		;

	h->prev->next = NULL;
	h->next = *stack;
	h->prev = NULL;
	(*stack)->prev = h;
	*stack = h;
}
