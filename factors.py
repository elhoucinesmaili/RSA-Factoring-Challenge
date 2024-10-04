import sys
import math

def factorize(n):
    # Start with trial division
    for i in range(2, int(math.isqrt(n)) + 1):
        if n % i == 0:
            return (i, n // i)
    return (n, 1)

def process_file(filename):
    with open(filename, 'r') as file:
        for line in file:
            num = int(line.strip())
            p, q = factorize(num)
            print(f"{num}={p}*{q}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        sys.exit(1)
    
    process_file(sys.argv[1])
