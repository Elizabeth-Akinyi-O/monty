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
		fprintf(stderr, "L%u: ", counter);
		fprintf(stderr, "usage: push integer\n");
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	for (a = 0; glob_var.arg[a] != '\0'; a++)
	{
		if (!isdigit(glob_var.arg[a]) && glob_var.arg[a] != '-')
		{
			fprintf(stderr, "L%u: ", counter);
			fprintf(stderr, "usage: push integer\n");
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
	stack_t *aux;
	(void)counter;

	aux = *stack;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
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
		fprintf(stderr, "L%u: ", counter);
		fprintf(stderr, "can't pint, stack empty\n");
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
	stack_t *aux;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", counter);
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	*stack = (*stack)->next;
	free(aux);
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
		fprintf(stderr, "L%u: can't swap, stack too short\n", counter);
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
