#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void factorize_number(long long n) {
    for (long long p = 2; p <= sqrt(n); p++) {
        if (n % p == 0) {
            long long q = n / p;
            printf("%lld=%lld*%lld\n", n, p, q);
            return; // Only print one factorization
        }
    }
    // If no factors found, print the number as is (which shouldn't happen for n > 1)
    printf("%lld=%lld*1\n", n, n);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    long long number;
    while (fscanf(file, "%lld", &number) != EOF) {
        factorize_number(number);
    }

    fclose(file);
    return 0;
}
