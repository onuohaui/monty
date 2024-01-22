#include "monty.h"

/**
 * op_rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number of the current operation.
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	top = *stack;
	bottom = *stack;

	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}

	/*Adjust the pointers to rotate the stack*/
	if (bottom->prev)
	{
		bottom->prev->next = NULL;
	}
	bottom->prev = NULL;
	bottom->next = top;
	top->prev = bottom;

	*stack = bottom;
}
