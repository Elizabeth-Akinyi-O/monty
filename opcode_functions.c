#include "monty.h"

/**
 * op_push - pushes an element to the stack
 * @stack: head of the linked list
 * @counter: line number
 *
 */
void op_push(stack_t **stack, unsigned int counter)
{
	int n, a;

	if (!glob_var.arg)
	{
		dprintf(2, "L%u: ", counter);
		dprintf(2, "usage: push integer\n");
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	for (a = 0; glob_var.arg[a] != '\0'; a++)
	{
		if (!isdigit(glob_var.arg[a]) && glob_var.arg[a] != '-')
		{
			dprintf(2, "L%u: ", counter);
			dprintf(2, "usage: push integer\n");
			free_glob_var();
			exit(EXIT_FAILURE);
		}

	}

	n = atoi(glob_var.arg);

	if (glob_var.lifo == 1)
		add_node_beg(stack, n);
	else
		add_node_end(stack, n);
}

/**
 * op_pall - prints all values on the stack
 * @stack: ehad of the linked list
 * @counter: line number
 *
 */
void op_pall(stack_t **stack, unsigned int counter)
{
	stack_t **h;
	(void)counter;

	h = *stack;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * op_pint - prints the value at the top of the stack
 * @stack: head of the linked list
 * @counter: line number
 *
 */
void op_pint(stack_t **stack, unsigned int counter)
{
	(void)counter;

	if (*stack == NULL)
	{
		dprintf(2, "L%u: ", counter);
		dprintf(2, "can't pint, stack empty\n");
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * op_pop - removes the top element of the stack
 * @stack: head of the linked list
 * @counter: line number
 *
 */
void op_pop(stack_t **stack, unsigned int counter)
{
	stack **h;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", counter);
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	h = *stack;
	*stack = (*stack)->next;
	free(h);
}

/**
 * op_swap - swaps the top two elements of the stack
 * @stack: head of the linked list
 * @counter: line number
 *
 */
void op_swap(stack_t **stack, unsigned int counter)
{
	int i = 0;
	stack_t *h = NULL;

	h = *stack;

	for (; h != NULL; h = h->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", counter);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	h = *stack;
	*stack = (*stack)->next;
	h->next = (*stack)->next;
	h->prev = *stack;
	(*stack)->next = h;
	(*stack)->prev = NULL;
}
