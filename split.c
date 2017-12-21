#include "monty.h"

int value;

/**
 * getop - compare token and opcode
 * @token: token received 
 * @stack: pointer to the stack
 * @line: line count
 */
void getop(char *token, stack_t *stack, unsigned int line)
{
	int i = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

printf("getop: %s\n", token);
	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(token, op[i].opcode) == 0)
		{
			op[i].f(&stack, line);
			return;
		}
	}
	printf("L%d: unknown instruction %s\n", line, token);
	exit(EXIT_FAILURE);
}

/**
 * gettoken - parse string and get token
 * @str: pointer to string
 * @line: line count
 */
void gettoken(char *str, unsigned int line)
{
	char *token;
	stack_t *stack = NULL;

printf("gettoken: %s\n", str);
/*	token = malloc(sizeof(char *) * 1);
	if (token == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	*/
	token = strtok(str, " "); 
printf("gettoken, token: %s\n", token);
	if (strcmp(token, "push") == 0)
	{
		value = atoi(strtok(NULL, " "));  /* Add check to ensure it's int?*/
		printf("push %d\n", value);
	}
	getop(token, stack, line);
/*	free(token);*/
}

/**
 * readfile - read a text file
 * @file: file to be read
 */
void readfile(const char *file)
{
	FILE *fp;
	char *buffer = NULL, *str;
	size_t size = 0;
	unsigned int line = 1;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
/*
	str = malloc(sizeof(char *) * 1);
	if (str == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}*/
	while (getline(&buffer, &size, fp) != -1)
	{
printf("buffer: %s\n", buffer);
	str = strtok(buffer, "\n");
printf("token: %s\n", str);
printf("L%u: readfile\n", line);
printf("token: %s\n", str);
		gettoken(str, line);
		line++;
		str = strtok(NULL, "\n");
	}
	fclose(fp);
	free(buffer);
	free(str);
}
