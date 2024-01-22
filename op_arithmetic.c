#include "monty.h"

/**
 * op_add - Adds the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number of the current operation.
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = sum;
	(*stack)->prev = NULL;
	free(temp);
}
