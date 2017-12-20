#include "monty.h"

extern int value;

/**
 * getop - compare token and opcode
 * @token: token received 
 * @line: line count
 */
void getop(char *token, unsigned int line)
{
	int i = 0;
	stack_t *stack = NULL;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop}
		{NULL, NULL}
	};

	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(token, op[i].opcode) == 0)
		{
			op[i].f(stack, line);
			return;
		}
	}
	printf("L%d: unknown instruction %s\n", line, token);
	exit(EXIT_FAILURE);
}

/**
 * readfile - read a text file
 * @file: file to be read
 */
void readfile(const char *file)
{
	FILE *fp;
	char *buffer = NULL, *op;
	size_t size = 0;
	unsigned int line = 0;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	op = malloc(sizeof(char *) * 2);
	if (op == NULL)
	(
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, fp) != -1)
	{
		op = strtok(buffer, " ");
		getop(op, line);
		line++;
	}
	fclose(fp);
	free(buffer);
}
