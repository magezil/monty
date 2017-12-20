#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: top of the stack
 * @line_number: current line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int top;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = pop(stack, line_number);
	value = top + pop(stack, line_number);
	push(stack, line_number);
}

/**
 * sub - adds the top two elements of the stack
 * @stack: top of the stack
 * @line_number: current line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int top;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = pop(stack, line_number);
	value = pop(stack, line_number) - top;
	push(stack, line_number);
}
