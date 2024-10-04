#include <stdio.h>
#include <stdlib.h>

/**
 * Function to find two factors of n.
 * Returns 1 if factors are found and 0 if the number is prime.
 */
int factorize(unsigned long long n) {
    unsigned long long i;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            printf("%llu=%llu*%llu\n", n, n / i, i);
            return 1;
        }
    }
    // If we reach here, n is prime or no factors found.
    printf("%llu=%llu*1\n", n, n);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    unsigned long long num;
    while (fscanf(file, "%llu", &num) != EOF) {
        factorize(num);
    }

    fclose(file);
    return 0;
}
