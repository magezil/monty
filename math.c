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
		freestack(stack, line_number);
		exit(EXIT_FAILURE);
	}

	top = value;
	pop(stack, line_number);
	top += value;
	pop(stack, line_number);
	value = top;
	push(stack, line_number);
}

/**
 * sub - subtracts the top element from the next top element of the stack
 * @stack: top of the stack
 * @line_number: current line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int top;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		freestack(stack, line_number);
		exit(EXIT_FAILURE);
	}

	top = value;
	pop(stack, line_number);
	top = value - top;
	pop(stack, line_number);
	value = top;
	push(stack, line_number);
}

/**
 * divide - divides the top element from the next top element of the stack
 * @stack: top of the stack
 * @line_number: current line number
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int top;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		freestack(stack, line_number);
		exit(EXIT_FAILURE);
	}
	if (value == 0)
	{
		printf("L%d: division by zero\n", line_number);
		freestack(stack, line_number);
		exit(EXIT_FAILURE);
	}

	top = value;
	pop(stack, line_number);
	top = value / top;
	pop(stack, line_number);
	value = top;
	push(stack, line_number);
}

/**
 * mul - multiplies the top two elements of the stack
 * @stack: top of the stack
 * @line_number: current line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int top;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		freestack(stack, line_number);
		exit(EXIT_FAILURE);
	}

	top = value;
	pop(stack, line_number);
	top *= value;
	pop(stack, line_number);
	value = top;
	push(stack, line_number);
}

/**
 * mod - computes the remainder of the division of the top element
 *       from the second to the top element of the stack
 * @stack: top of the stack
 * @line_number: current line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int top;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		freestack(stack, line_number);
		exit(EXIT_FAILURE);
	}
	if (value == 0)
	{
		printf("L%d: division by zero\n", line_number);
		freestack(stack, line_number);
		exit(EXIT_FAILURE);
	}

	top = value;
	pop(stack, line_number);
	top = value % top;
	pop(stack, line_number);
	value = top;
	push(stack, line_number);
}
