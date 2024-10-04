import math

def factorize(n):
    # Try to find two factors of n
    for i in range(2, int(math.isqrt(n)) + 1):
        if n % i == 0:
            return (n // i, i)  # Return the two factors
    return (n, 1)  # If no factor is found, return n and 1 (n is prime)

def process_file(filename):
    # Read the file and process each number
    with open(filename, 'r') as file:
        for line in file:
            num = int(line.strip())  # Convert the line to an integer
            p, q = factorize(num)  # Factorize the number
            print(f"{num}={p}*{q}")  # Print the result

if __name__ == "__main__":
    filename = "numbers.txt"  # Example file name containing the numbers
    process_file(filename)
