#include "monty.h"

/**
 * op_pall - Prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number of the current operation.
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * op_pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number of the current operation.
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
