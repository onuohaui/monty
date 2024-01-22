#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * enum mode_e - Operation mode of the Monty interpreter
 * @STACK_MODE: Stack mode
 * @QUEUE_MODE: Queue mode
 */
typedef enum mode_e
{
	STACK_MODE,
	QUEUE_MODE
} mode_t;

/**
 * struct stack_info_s - Holds the stack and mode information
 * @stack: The stack
 * @mode: The mode (STACK_MODE or QUEUE_MODE)
 */
typedef struct stack_info_s
{
	stack_t *stack;
	mode_t mode;
} stack_info_t;

/* Function prototypes for opcode functions */
void op_push(stack_info_t *info, unsigned int line_number, char *arg);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
int is_number(char *str);
void op_sub(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);
void op_pchar(stack_t **stack, unsigned int line_number);
void op_pstr(stack_t **stack, unsigned int line_number);
void op_rotl(stack_t **stack, unsigned int line_number);
void op_rotr(stack_t **stack, unsigned int line_number);
void op_stack(stack_info_t *info, unsigned int line_number);
void op_queue(stack_info_t *info, unsigned int line_number);

/* Utility function prototypes */
void free_stack(stack_t **stack);
void clean_up(stack_t **stack, FILE *file, int status);

/* New function prototypes for main.c refactoring */
void open_file(char *filename, FILE **file);
void process_lines(FILE *file, stack_info_t *info);

#endif /* MONTY_H */

