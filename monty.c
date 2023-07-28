#include "monty.h"

/**
 * monty_interpreter - Interprets Monty ByteCodes from a given file.
 * @bytecode_file: A pointer to the Monty ByteCodes file to be interpreted.
 *
 * Description:reads the Monty ByteCodes file line by line and executes
 * the corresponding opcode functions.
 */

void monty_interpreter(FILE *bytecode_file)
{
	char line[1024];
	char *opcode, *arg;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	int i;
	size_t len = 0;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	while (fgets(line, sizeof(line), bytecode_file))
	{
		line_number++;
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		tokenize_line(line, &opcode, &arg);
		i = 0;
		while (instructions[i].opcode != NULL)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				break;
			}
			i++;
		}
		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			fclose(bytecode_file);
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}
	}
	fclose(bytecode_file);
	free_stack(&stack);
}

/**
* free_stack - Frees the stack
* @stack: Pointer
* */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
