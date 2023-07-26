#include "monty.h"
/**
* main - Entry point
* @argc: Number of cmd args
* @argv: Array of args
*
* Return: 0 on success or fail
*/

int main(int argc, char *argv[])
{
	FILE *bytecode_file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}
	bytecode_file = fopen(argv[1], "r");
	if (!bytecode_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	monty_interpreter(bytecode_file);
	return (EXIT_SUCCESS);
}
