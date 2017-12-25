import math
import sys

# recursive function to find how many ways X can be expressed as the sum of the Nth power of uunique, natural numbers
def calc_permutations(X, P, N):
    solutions = 0

    #termination condition
    if pow(N, P) > X:
        return solutions

    # we found a solution
    elif pow(N, P) == X:
        solutions += 1    

    #recursively sum all solutions
    solutions += calc_permutations(X-pow(N, P), P, N+1)
    solutions += calc_permutations(X, P, N+1)

    return solutions

def main():
    X = int(sys.stdin.readline())
    P = int(sys.stdin.readline())

    print(calc_permutations(X, P, 1))

if __name__ == "__main__":
    main()
