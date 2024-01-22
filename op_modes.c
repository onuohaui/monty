#include "monty.h"

mode_t mode = STACK_MODE;

/**
 * op_stack - Sets the mode to stack (LIFO).
 * @stack: Double pointer to the head of the stack (unused in this function).
 * @line_number: The line number of the current operation (unused in this function).
 */
void op_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = STACK_MODE;
}

/**
 * op_queue - Sets the mode to queue (FIFO).
 * @stack: Double pointer to the head of the stack (unused in this function).
 * @line_number: The line number of the current operation (unused in this function).
 */
void op_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = QUEUE_MODE;
}
