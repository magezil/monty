#include "monty.h"

/**
 * main - entry point of the program
 * @ac: numbers of aurgments
 * @av: arguments received
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
