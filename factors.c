#include <stdio.h>
#include <stdlib.h>

void factorize(long n) {
    for (long i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            long j = n / i;
            printf("%ld=%ld*%ld\n", n, j, i);
            return; // Return after finding the first pair of factors
        }
    }
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

    long number;
    while (fscanf(file, "%ld", &number) == 1) {
        factorize(number);
    }

    fclose(file);
    return 0;
}

