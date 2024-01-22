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

/**
 * op_sub - Subtracts the top element of the stack from the second top element.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number of the current operation.
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int difference;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	difference = (*stack)->next->n - (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = difference;
	(*stack)->prev = NULL;

	free(temp);
}

#include "monty.h"

/**
 * op_div - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number of the current operation.
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int quotient;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	quotient = (*stack)->next->n / (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = quotient;
	(*stack)->prev = NULL;
	free(temp);
}
