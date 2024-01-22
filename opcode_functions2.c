#include "monty.h"

/**
 * op_div - divides the 2nd element by the top element of the stack
 * @stack: head of the linked list
 * @counter: line number
 *
 */
void op_div(stack_t **stack, unsigned int counter)
{
	int i = 0;
	stack_t *h = NULL;

	h = *stack;

	for (; h != NULL; h = h->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", counter);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", counter);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	h = (*stack)->next;
	h->n /= (*stack)->n;
	op_pop(stack, counter);
}

/**
 * op_mul - multiplies the top element to the 2nd top element of the stack
 * @stack: head of the linked list
 * @counter: line number
 *
 */
void op_mul(stack_t **stack, unsigned int counter)
{
	int i = 0;
	stack_t *h = NULL;

	h = *stack;

	for (; h != NULL; h = h->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", counter);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	h = (*stack)->next;
	h->n *= (*stack)->n;
	op_pop(stack, counter);
}

/**
 * op_mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @stack: head of the linked list
 * @counter: line number
 *
 */
void op_mod(stack_t **stack, unsigned int counter)
{
	int i = 0;
	stack_t *h = NULL;

	h = *stack;
	for (; h != NULL; h = h->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", counter);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", counter);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	h = (*stack)->next;
	h->n %= (*stack)->n;
	op_pop(stack, counter);
}

/**
 * op_pchar - prints the char at the top of the stack
 * @stack: head of the linked list
 * @counter: line number
 *
 */
void op_pchar(stack_t **stack, unsigned int counter)
{
	if (stack  == NULL || *stack == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", counter);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", counter);
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * op_pstr - prints the string starting at the top of the stack
 * @stack: head of the linked list
 * @counter: line number
 *
 */
void op_pstr(stack_t **stack, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *stack;

	while (h && h->n > 0 && h->n < 128)
	{
		printf("%c", h->n);
		h = h->next;
	}

	printf("\n");
}
