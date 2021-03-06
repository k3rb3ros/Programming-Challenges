/*
 * By k3rbr3os on 02/03/2015
 * Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be: 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 * By considering the terms in the Fibonacci sequence whose values do net exceed four million, find the sum of the even-valued terms.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#define FIB_MAT  { {1, 1}, {1, 0} }
#define LIMIT 4000000

static inline bool even(const uint64_t number)
{
    return number % 2 == 0;
}

//google tells us that the fastest way to get the nth+1 fibanacci number is by multiplying the matrix FIB_MAT n times
static inline void matrixMultiply(uint64_t mat_F[2][2], const uint64_t mat_M[2][2])
{
    //This is the matrix product of a 2x2 matrix
    uint64_t w = (mat_F[0][0]*mat_M[0][0]) + (mat_F[0][1]*mat_M[1][0]);
    uint64_t x = (mat_F[0][0]*mat_M[0][1]) + (mat_F[0][1]*mat_M[1][1]);
    uint64_t y = (mat_F[1][0]*mat_M[0][0]) + (mat_F[1][1]*mat_M[1][0]);
    uint64_t z = (mat_F[1][0]*mat_M[0][1]) + (mat_F[1][1]*mat_M[1][1]);

    mat_F[0][0] = w;
    mat_F[0][1] = x;
    mat_F[1][0] = y;
    mat_F[1][1] = z;
}

static inline void matrixPower(uint64_t mat_F[2][2], uint64_t n)
{
    uint64_t mat_M [2][2] = FIB_MAT;

    for(; n>0; --n) { matrixMultiply(mat_F, mat_M); }
}

static uint64_t fibonacci(const uint64_t number)
{
   if(number <= 1) return 1; //fibonacci 0, 1 = 1

   uint64_t mat_F[2][2] = FIB_MAT;
   matrixPower(mat_F, number-1); //multiply the matrix nth power
   
   return mat_F[0][0];
}

int main(void)
{
    //By considering the terms in the Fibonacci sequence whose VALUES do net exceed four million, find the sum of the even-valued terms.
    printf("Sum of even fibonacci numbers less than 4,000,000: ");
    uint64_t count = 1;
    uint64_t fib = 0;
    uint64_t sum = 0; 

    while(fib < LIMIT)
    {
	fib = fibonacci(count++);
	if(even(fib)) { sum += fib; }
    }

    printf("%lu\n", sum);
    return 0;
}
