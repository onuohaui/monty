#include "monty.h"

/**
 * op_stack - Sets the mode to stack (LIFO).
 * @info: Pointer to the stack and mode information.
 * @line_number: The line number of the current
 * operation (unused in this function).
 */
void op_stack(stack_info_t *info, unsigned int line_number)
{
	(void)line_number;
	if (info)
	{
		info->mode = STACK_MODE;
	}
}

/**
 * op_queue - Sets the mode to queue (FIFO).
 * @info: Pointer to the stack and mode information.
 * @line_number: The line number of the current
 * operation (unused in this function).
 */
void op_queue(stack_info_t *info, unsigned int line_number)
{
	(void)line_number;
	if (info)
	{
		info->mode = QUEUE_MODE;
	}
}
