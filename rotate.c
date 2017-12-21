#include "monty.h"

/**
 * rotl - rotates the stack to the top so the top goes to the bottom
 *        and the next top becomes the new top
 * @stack: top of the stack
 * @line_number: current line number
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next->next = NULL;
}

/**
 * rotr - rotates the stack to the bottom so the top goes to the bottom
 *        and the bottom becomes the new top
 * @stack: top of the stack
 * @line_number: current line number
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	*stack = temp;
}
