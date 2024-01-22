#include "monty.h"

global_t glob_var;

/**
 * free_glob_var - frees global variables
 *
 */
void free_glob_var(void)
{
	free_nodes(glob_var.head);
	free(glob_var.buff);
	fclose(glob_var.fd);
}

/**
 * start_glob_var - initializes global variables
 * @fd: file descriptor
 *
 */
void start_glob_var(FILE *fd)
{
	glob_var.lifo = 1;
	glob_var.l_cont = 1;
	glob_var.arg = NULL;
	glob_var.head = NULL;
	glob_var.fd = fd;
	glob_var.buff = NULL;
}

/**
 * check_file - checks if the file exists and can be opened
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: file struct
 */
FILE *check_file(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - main entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (succes)
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t b_size = 256;/* initial size for the getline buffer*/
	ssize_t nlines = 0;
	char *token[2] = {NULL, NULL};

	fd = check_file(argc, argv);
	start_glob_var(fd);
	nlines = getline(&glob_var.buff, &b_size, fd);
	while (nlines != -1)
	{
		token[0] = _strtokk(glob_var.buff, " \t\n");
		if (token[0] && token[0][0] != '#')
		{
			f = exec_opcode(token[0]);
			if (!f)
			{
				fprintf(stderr, "L%u: ", glob_var.l_cont);
				fprintf(stderr, "unknown instruction %s\n", token[0]);
				free_glob_var();
				exit(EXIT_FAILURE);
			}
			glob_var.arg = _strtokk(NULL, " \t\n");
			f(&glob_var.head, glob_var.l_cont);
		}
		nlines = getline(&glob_var.buff, &b_size, fd);
		glob_var.l_cont++;
	}

	free_glob_var();

	return (0);
}
