#include "monty.h"

/**
 * qpush - add value to a queue
 * @stack: head of queue
 * @line_number: current line number
 */
void qpush(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	stack_t *temp;

	if (stack == NULL)
	{
		printf("L%d: invalid stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		freestack(stack, line_number);
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	value = (*stack)->n;
}
