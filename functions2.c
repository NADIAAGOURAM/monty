#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: stack input
 * @line_number: int input
 * Return: void.
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop -  doesn’t do anything.
 * @stack: stack input
 * @line_number: int input
 * Return: void.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
