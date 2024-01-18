#include "monty.h"

/**
 * main - Entry point for the Monty ByteCode interpreter
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *filename;
	char line[1024];
	unsigned int line_number = 0;
	char *opcode;
	char *arg;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");

	}

	fclose(file);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
