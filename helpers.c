#include "monty.h"

/**
 * create_node - adds a new node at the beginning of a list_t list
 * @n:Value to be stored
 *
 * Return: the address of the new element, or NULL if it fails
 */
stack_t *create_node(int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

/**
 * tokenize_line - tokenize the input line and extract the opcode and argument
 * @line:A pointer to a string representing a line of Monty ByteCodes file
 * @opcode: A pointer to a pointer to a string.to store the extracted opcode.
 * @arg:A pointer to a pointer to a string.to store the extracted argument
 *
 */
void tokenize_line(char *line, char **opcode, char **arg)
{
	*opcode = strtok(line, " \t\n");
	*arg = strtok(NULL, " \t\n");
}
