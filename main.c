#include "monty.h"

extern int value;

/**
 * readfile - Read a text file
 * @file: File to be read
 * @size: size_t holder, initilized 0 when coming in
 * Return: TBD, 0 for now
 */
int readfile(const char *file, size_t size)
{
	FILE *fp;
	ssize_t read;
	char *buffer = NULL;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", file);
		return(EXIT_FAILURE);
	}
	read = getline(&buffer, &size, fp)
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
	size_t size = 0;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	readfile(av[1], size);

	return (0);
}
