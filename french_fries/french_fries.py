'''
This script calculates the number of ways there are to eat a plate of french fries assuming, the eater consumes one or two fries at a time.
'''
import argparse
import itertools

def nth_fibo(n):
    fibo = 0

    if (type(n) is not int or n < 0):
        fibo = 0
    elif (n == 1):
        fibo = 1
    elif (n == 2):
        fibo = 2
    else:
        fib = 0
        f1 = 0
        f2 = 1
        temp = 0

        for i in range(n):
            temp = f2
            fib = f1 + f2
            f1 = temp
            f2 = fib
        fibo = fib

    return fibo

'''The number of permutatations of ways fries can be eaten can be expressed 
   as the fibonacci sequence of n
'''
def calc_mathmatically(fries):
    perm = 0
    if (type(fries) is not int or fries <= 0):
        perm = 0
    else :
        perm = nth_fibo(fries)

    return perm

def main():
    parser = argparse.ArgumentParser(description='Read the number of french fries and output the number of permutations of 1 and 2 frie eating possibilities.')
    parser.add_argument('num_fries', type=int, help='the number of fries to compute the permutation for')
    args = parser.parse_args()
    global Fries
    Fries = args.num_fries

    if (type(Fries) is int):
        print(str(calc_mathmatically(Fries)) + ' Ways to eat ' + str(Fries) + ' fries')
    else :
        print('Invalid input')

if __name__ == "__main__": main()
