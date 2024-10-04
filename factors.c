#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - finds two factors of a given number
 * @n: the number to be factorized
 * Return: 1 if factors found, 0 if prime
 */
int factorize(unsigned long long n)
{
	unsigned long long i;

	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			printf("%llu=%llu*%llu\n", n, n / i, i);
			return (1);
		}
	}
	printf("%llu=%llu*1\n", n, n);
	return (0);
}

/**
 * main - entry point for the factorization program
 * @argc: argument count
 * @argv: argument vector (array of strings)
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	FILE *file;
	unsigned long long num;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		perror("Error opening file");
		return (1);
	}

	while (fscanf(file, "%llu", &num) != EOF)
	{
		factorize(num);
	}

	fclose(file);
	return (0);
}
