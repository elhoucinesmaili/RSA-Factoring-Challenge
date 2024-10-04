#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void factorize(unsigned long long n)
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
    // If no factor is found, it's a prime or large composite number
    printf("%llu=1*%llu\n", n, n);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        unsigned long long number = strtoull(line, NULL, 10);
        factorize(number);
    }

    fclose(file);
    return 0;
}
