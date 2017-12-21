#include "monty.h"

/**
 * push - adds a value to the beginning of a list
 * @stack: top of the stack
 * @line_number: current line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL)
	{
		printf("L%d: invalid stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		while (*stack != NULL)
			pop(stack, line_number);
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints all values on a stack
 * @stack: top of the stack
 * @line_number: current line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL)
	{
		printf("L%d: invalid stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - print value at top of stack
 * @stack: top of the stack
 * @line_number: current line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* printf("%d\n", value); */
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of a stack
 * @stack: top of the stack
 * @line_number: current line number
 * Return: value of popped node
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		value = (*stack)->n;
		free((*stack)->prev);
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * swap - swaps top two elements of a stack
 * @stack: top of the stack
 * @line_number: current line number
 *
 * Return: deleted node
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: swap, stack too short\n", line_number);
		while (*stack != NULL)
			pop(stack, line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	temp->prev = *stack;
	temp->next = (*stack)->next;
	(*stack)->prev = NULL;
	(*stack)->next = temp;
	value = (*stack)->n;
}
