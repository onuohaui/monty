#include "monty.h"

extern mode_t mode;

/**
 * op_push - Pushes an element to the stack or queue based on the current mode.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number of the current operation.
 * @arg: The argument to push.
 */
void op_push(stack_t **stack, unsigned int line_number, char *arg)
{
	int num;
	stack_t *new_node, *temp;

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
	new_node->next = NULL;

	if (mode == QUEUE_MODE && *stack != NULL)
	{
		/*Add to the end of the queue*/
		temp = *stack;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->prev = temp;
	}
	else
	{
		/*Add to the top of the stack*/
		new_node->next = *stack;
		if (*stack != NULL)
		{
			(*stack)->prev = new_node;
		}
		*stack = new_node;
	}
}
