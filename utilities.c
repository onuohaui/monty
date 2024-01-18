#include "monty.h"

/**
 * free_stack - Frees a stack.
 * @stack: The stack to be freed.
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	if (stack == NULL)
		return;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

/**
 * is_number - Check if a string is a number.
 * @str: The string to check.
 *
 * Return: 1 if string is a number, 0 otherwise.
 */
int is_number(char *str)
{
	if (*str == '-' ||
			*str == '+')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * print_error - Prints custom error messages.
 * @line_number: Line number where the error occurred.
 * @message: Error message to print.
 */
void print_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%d: %s\n", line_number, message);
}

/**
 * clean_up - Frees memory and handles any finalization before exiting.
 * @stack: The stack to be freed.
 * @file: File pointer to be closed if not NULL.
 * @status: Exit status.
 */
void clean_up(stack_t **stack, FILE *file, int status)
{
	if (file)
		fclose(file);
	free_stack(stack);
	exit(status);
}
