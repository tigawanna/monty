#include "monty.h"

/**
 * swap - swaps 2 elements in a stack
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *tmp;

	tmp = (*stack)->next;
	(*stack)->prev = tmp;
	(*stack)->next = tmp;

	tmp->prev = NULL;

	if (tmp->next != NULL)
	{
		tmp->next->prev = *stack;
	}

	tmp->next = *stack;
	*stack = tmp;

}
