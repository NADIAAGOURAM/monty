#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: stack input
 * @line_number: int input
 * Return: void.
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int value;
	stack_t *new_node;

	/* Extract the argument from the opcode line */
	*arg = strtok(NULL, " \t\n");
	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Convert the argument to an integer */
	value = atoi(arg);
	/* Create a new node and push it to the stack */
	new_node = create_node(value);
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: stack input
 * @line_number: int input
 * Return: void.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
