#include "monty.h"

void open_file(char *filename, FILE **file);
void process_lines(FILE *file, stack_t **stack);


/**
 * main - Entry point of the Monty ByteCode interpreter.
 * @argc: The number of command-line arguments.
 * @argv: Array of pointers to the arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	open_file(argv[1], &file);
	process_lines(file, &stack);
	clean_up(&stack, file, EXIT_SUCCESS);

	return (EXIT_SUCCESS);
}

/**
 * open_file - Opens a file for reading.
 * @filename: The name of the file to be opened.
 * @file: Double pointer to the file
 * structure where the opened file will be stored.
 */
void open_file(char *filename, FILE **file)
{
	*file = fopen(filename, "r");
	if (!*file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * process_lines - Processes each line of the
 * opened Monty bytecode file.
 * @file: Pointer to the opened file.
 * @stack: Double pointer to the top of the stack.
 */
void process_lines(FILE *file, stack_t **stack)
{
	char line[1024];
	unsigned int line_number = 0;
	char *opcode, *arg;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		/*Check if the line is a comment or empty*/
		if (opcode == NULL || opcode[0] == '#')
		{
			continue;
		}
		arg = strtok(NULL, " \t\n");

		if (strcmp(opcode, "push") == 0)
		{
			op_push(stack, line_number, arg);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			op_pall(stack, line_number);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			op_pint(stack, line_number);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			op_pop(stack, line_number);
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			op_swap(stack, line_number);
		}
		else if (strcmp(opcode, "add") == 0)
		{
			op_add(stack, line_number);
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			op_nop(stack, line_number);
		}
		else if (strcmp(opcode, "sub") == 0)
		{
			op_sub(stack, line_number);
		}
		else if (strcmp(opcode, "div") == 0)
		{
			op_div(stack, line_number);
		}
		else if (strcmp(opcode, "mul") == 0)
		{
			op_mul(stack, line_number);
		}
		else if (strcmp(opcode, "mod") == 0)
		{
			op_mod(stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			clean_up(stack, file, EXIT_FAILURE);
		}
	}
}
