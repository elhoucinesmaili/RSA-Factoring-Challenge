#include <stdio.h>
#include <stdlib.h>

/**
 * Function to factorize a number into two factors.
 * The factors don't need to be prime.
 * @param num: The number to factorize.
 */
void factorize(unsigned long long num)
{
    unsigned long long p;

    /* Start with p = 2 and find the first divisor */
    for (p = 2; p * p <= num; p++)
    {
        if (num % p == 0)
        {
            /* If p divides num, find q = num / p */
            unsigned long long q = num / p;
            printf("%llu=%llu*%llu\n", num, q, p);
            return;
        }
    }
    /* If no divisors are found, assume the number is prime */
    printf("%llu=%llu*1\n", num, num);
}

int main(int argc, char *argv[])
{
    FILE *file;
    char line[256];
    unsigned long long num;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    /* Open the file provided as an argument */
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    /* Read each line from the file */
    while (fgets(line, sizeof(line), file))
    {
        /* Convert the line (string) to an unsigned long long */
        num = strtoull(line, NULL, 10);

        /* Factorize the number */
        factorize(num);
    }

    /* Close the file */
    fclose(file);

    return 0;
}
