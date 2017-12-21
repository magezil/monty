#include "monty.h"

/**
 * freestack - frees the stack
 * @stack - stack to free
 * @line_number - current line number
 */
void freestack(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		return;

	while (*stack != NULL)
		pop(stack, line_number);
}
