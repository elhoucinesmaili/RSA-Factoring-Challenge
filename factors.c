#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * trial_division - Function to perform trial division to find two factors
 * @n: The number to factorize
 *
 * Return: Nothing, prints the factorization in the format n = p * q
 */
void trial_division(unsigned long long n)
{
    unsigned long long i;

    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            printf("%llu=%llu*%llu\n", n, i, n / i);
            return;
        }
    }
    printf("%llu=%llu*1\n", n, n);
}

/**
 * main - Entry point of the program
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned long long num;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return (1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return (1);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        num = strtoull(line, NULL, 10);
        trial_division(num);
    }

    fclose(file);
    if (line)
        free(line);

    return (0);
}
