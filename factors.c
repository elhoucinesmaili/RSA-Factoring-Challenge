#include <stdio.h>
#include <stdlib.h>

long long factorize(long long n) {
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            return p;  // Return the first factor found
        }
    }
    return n;  // If no factor found, return n itself (it is prime)
}

void factorize_numbers(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    long long n;
    while (fscanf(file, "%lld", &n) != EOF) {
        long long p = factorize(n);
        long long q = n / p;
        printf("%lld=%lld*%lld\n", n, p, q);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: factors <file>\n");
        return EXIT_FAILURE;
    }

    factorize_numbers(argv[1]);
    return EXIT_SUCCESS;
}
