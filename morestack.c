#include "monty.h"

/**
 * freestack - frees the stack
 * @stack: stack to free
 * @line_number: current line number
 */
void freestack(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		return;
	while (*stack != NULL)
		pop(stack, line_number);
}

/**
 * pchar - prints char at top of stack
 * @stack: top of the stack
 * @line_number: current line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!isascii(value))
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", value);
}

/**
 * pstr - prints string starting at top of stack
 * @stack: top of the stack
 * @line_number: current line number
 */
void pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || !isascii(value) || value == 0)
	{
		printf("\n");
		return;
	}
	temp = *stack;
	for (; temp != NULL && temp->n != 0 && isascii(temp->n); temp = temp->next)
		printf("%c", temp->n);
	printf("\n");
}
