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
	char *opcode;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	int i = 0;

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

		opcode = strtok(line, " \t\n");
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
			exit(EXIT_FAILURE);
		}
	}
	fclose(bytecode_file);
}
