#include "monty.h"

/**
 * exec_opcode - selects the correct opcode to execute
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*exec_opcode(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t opinst[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"queue", op_queue},
		{"stack", op_stack},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"mul", op_mul},
		{"div", op_div},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"totr" op_rotr},
		{NULL, NULL}
	};
	int a;

	for (a = 0; opinst[a].opcode; a++)
	{
		if (_strcmpp(opinst[a].opcode, opc) == 0)
			break;
	}

	return (opinst[a].f);
}
