#include "monty.h"

void add_to_queue(stack_t **stack, stack_t *new_node);

/**
 * op_push - Pushes an element to the stack or queue based on the current mode.
 * @info: Pointer to the stack and mode information.
 * @line_number: The line number of the current operation.
 * @arg: The argument to push.
 */
void op_push(stack_info_t *info, unsigned int line_number, char *arg)
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
	new_node->next = NULL;

	if (info->mode == QUEUE_MODE && info->stack != NULL)
	{
		add_to_queue(&info->stack, new_node);
	}
	else
	{
		/* Add to the top of the stack */
		new_node->next = info->stack;
		if (info->stack != NULL)
		{
			info->stack->prev = new_node;
		}
		info->stack = new_node;
	}
}

/**
 * add_to_queue - Adds a new node to the end of the queue.
 * @stack: Double pointer to the head of the stack.
 * @new_node: The new node to add.
 */
void add_to_queue(stack_t **stack, stack_t *new_node)
{
	stack_t *temp = *stack;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;
}
