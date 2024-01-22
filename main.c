#include "monty.h"

void open_file(char *filename, FILE **file);
void process_lines(FILE *file, stack_info_t *info);
void clean_up(stack_t **stack, FILE *file, int status);

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
	stack_info_t info = {NULL, STACK_MODE};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	open_file(argv[1], &file);
	process_lines(file, &info);
	clean_up(&info.stack, file, EXIT_SUCCESS);

	return (EXIT_SUCCESS);
}

/**
 * open_file - Opens a file for reading.
 * @filename: The name of the file to be opened.
 * @file: Double pointer to the file structure where the opened file will be stored.
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
 * process_lines - Processes each line of the opened Monty bytecode file.
 * @file: Pointer to the opened file.
 * @info: Pointer to the stack and mode information.
 */
void process_lines(FILE *file, stack_info_t *info)
{
	char line[1024];
	unsigned int line_number = 0;
	char *opcode, *arg;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		/* Check if the line is a comment or empty */
		if (opcode == NULL || opcode[0] == '#')
		{
			continue;
		}
		arg = strtok(NULL, " \t\n");

		if (strcmp(opcode, "push") == 0)
		{
			op_push(info, line_number, arg);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			op_pall(&info->stack, line_number);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			op_pint(&info->stack, line_number);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			op_pop(&info->stack, line_number);
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			op_swap(&info->stack, line_number);
		}
		else if (strcmp(opcode, "add") == 0)
		{
			op_add(&info->stack, line_number);
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			op_nop(&info->stack, line_number);
		}
		else if (strcmp(opcode, "sub") == 0)
		{
			op_sub(&info->stack, line_number);
		}
		else if (strcmp(opcode, "div") == 0)
		{
			op_div(&info->stack, line_number);
		}
		else if (strcmp(opcode, "mul") == 0)
		{
			op_mul(&info->stack, line_number);
		}
		else if (strcmp(opcode, "mod") == 0)
		{
			op_mod(&info->stack, line_number);
		}
		else if (strcmp(opcode, "pchar") == 0)
		{
			op_pchar(&info->stack, line_number);
		}
		else if (strcmp(opcode, "pstr") == 0)
		{
			op_pstr(&info->stack, line_number);
		}
		else if (strcmp(opcode, "rotl") == 0)
		{
			op_rotl(&info->stack, line_number);
		}
		else if (strcmp(opcode, "rotr") == 0)
		{
			op_rotr(&info->stack, line_number);
		}
		else if (strcmp(opcode, "stack") == 0)
		{
			op_stack(info, line_number);
		}
		else if (strcmp(opcode, "queue") == 0)
		{
			op_queue(info, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			clean_up(&info->stack, file, EXIT_FAILURE);
		}
	}
}
