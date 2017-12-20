#include "monty.h"

extern int value;

/**
 * readfile - Read a text file
 * @file: File to be read
 * Return: 0
 */
int readfile(const char *file)
{
	FILE *fp;
	char *buffer = NULL;
	size_t size = 0;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", file);
		return(EXIT_FAILURE);
	}
	while(getline(&buffer, &size, fp) != -1)
	{
		
	}
	fclose(fp);
	free(buffer);
	return (0);
}

/**
 * main - Entry point of the program
 * @ac: The number of aurgments
 * @av: Arguments received 
 * Return: 0
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	readfile(av[1]);

	return (0);
}
