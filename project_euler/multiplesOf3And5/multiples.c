#include <stdbool.h>
#include <stdio.h>

#define CHECK_RANGE 1000

/*
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

static inline bool isMultipleOf3(int number)
{
    return number % 3 == 0;
}

static inline bool isMultipleOf5(int number)
{
    return number % 5 == 0;
}

int main()
{
    int sum = 0;
   
    for(int i=0; i<CHECK_RANGE; ++i)
    {
        if(isMultipleOf3(i) || isMultipleOf5(i)) { sum += i; }    
    }

    printf("Sum of all multiples of 3 and 5 from 0-999 is %d \n", sum);

    return 0;
}
