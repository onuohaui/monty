#include "monty.h"

/**
 * op_add - Adds the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number of the current operation.
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + (*stack)->next->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = result;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * op_nop - Doesn’t do anything.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number of the current operation.
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
