#include "monty.h"

extern int value;

/**
 * add - adds the top two elements of the stack
 * @stack: top of the stack
 * @line_number: current line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = pop(stack, line_number);
	sum += pop(stack, line_number);
	value = sum;
	push(stack, line_number);
}

/**
 * sub - adds the top two elements of the stack
 * @stack: top of the stack
 * @line_number: current line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int dif;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	dif = pop(stack, line_number);
	dif -= pop(stack, line_number);
	value = dif;
	push(stack, line_number);
}
