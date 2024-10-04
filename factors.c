#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Function to factorize a number and print the result in the format n=p*q.
 */
void factorize(unsigned long long n) {
    unsigned long long p;
    for (p = 2; p <= sqrt(n); p++) {
        if (n % p == 0) {
            printf("%llu=%llu*%llu\n", n, p, n / p);
            return;
        }
    }
    // If no factors are found, n is a prime number, return n=n*1
    printf("%llu=%llu*1\n", n, n);
}

/**
 * Main function to read from the file and factorize each number.
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        unsigned long long n = strtoull(line, NULL, 10);
        factorize(n);
    }

    fclose(file);
    return 0;
}

