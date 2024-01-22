#include "monty.h"

/**
 * op_push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number of the current operation.
 * @arg: The argument to push.
 */
void op_push(stack_t **stack, unsigned int line_number, char *arg)
{
	int num;
	stack_t *new_node;

	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
