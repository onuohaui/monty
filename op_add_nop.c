#include "monty.h"

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
