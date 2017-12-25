#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static inline void clearBuff(uint8_t* buff, size_t byte_size)
{
    for (;byte_size > 0;buff++,byte_size--)
    {
        *buff = 0;
    }
}

static inline int_fast32_t countInversions(const int_fast32_t* arr, const size_t len)
{
    int_fast32_t inv = 0;

    for (size_t s=0; s<(len-1); ++s)
    {
        for(size_t t=(s+1); t<len; ++t)
        {
            if (arr[s] > arr[t]) { inv++; }
        }
    }

    return inv;
}

static void printArray(const int_fast32_t* arr, size_t len)
{
    printf("[");
    for (;len>0 ;arr++,len--)
    {
        printf("%d", *arr);
        if (len > 1) { printf(", "); }
    }
    printf("]\n");
}

static inline void swap(int_fast32_t* arr, const size_t ind1, const size_t ind2)
{
    //printf("swap(%zd, %zd)\n", arr[ind1], arr[ind2]);
    int_fast32_t temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}

static int_fast32_t mergeInBuffer(int_fast32_t* data, int_fast32_t* bfr, const size_t l_bound, const size_t r_bound)
{
    int inv = 0;
    const size_t l_upper = (l_bound + r_bound) / 2;
    const size_t size = (r_bound-l_bound)+1;

    printf("mergeInBuffer l_upper:%zd size:%zd\n", l_upper, size);

    size_t l_ind = l_bound;
    size_t r_ind = l_upper + 1;
    size_t b_ind = 0;

    if (l_bound < r_bound)
    {
        printArray(&data[l_bound], size);
        while (l_ind <= l_upper && r_ind <= r_bound)
        {
            if (data[l_ind] <= data[r_ind])
            {
                bfr[b_ind] = data[l_ind];
                l_ind++;
            }
            else
            {
                bfr[b_ind] = data[r_ind];
                r_ind++;
                inv += (r_ind-l_ind);
            }
            b_ind++;
        }
    }

    memcpy(&bfr[b_ind], &data[l_ind], (l_upper - l_ind)+1);
    memcpy(&bfr[b_ind], &data[r_ind], (r_bound - r_ind)+1);
    printArray(bfr, size);
    memcpy(&data[l_bound], bfr, size);

    return inv;
}

//this merge is improved it doesn't need a tempory buffer like typical merge implmentations do it just swaps in place
static void mergeInPlace(int_fast32_t* arr, const size_t l_bound, const size_t r_bound)
{
    if (l_bound == r_bound ) { return; }
    //printf("merge(%zd, %zd)\n", l_bound, r_bound);
    //printArray(&arr[l_bound], (r_bound-l_bound)+1);

    size_t l_ind = l_bound;
    size_t r_ind = ((l_bound + r_bound) / 2) + 1;

    for (size_t s=0; s<(r_bound-l_bound); ++s)
    {
        bool swap_ = false;
        //printf("comparing %zd, %zd\n", arr[l_ind], arr[r_ind]);
        if (arr[l_ind] > arr[r_ind])
        {
            swap_ = true;
            swap(arr, l_ind, r_ind);
            l_ind++;
        }

        if (r_ind < r_bound) { ++r_ind; }
        else //roll r_ind over if their could still be swaps to be made
        {
            if (!swap_) { l_ind++; }
            r_ind = ((l_bound + r_bound/2) + 1);
        }
    }
    //printArray(&arr[l_bound], (r_bound-l_bound)+1);
}

//because my merge sort is better (not neading an in place array
int_fast32_t mergeSort(int_fast32_t* data, int_fast32_t* bfr, const size_t l_bound, const size_t r_bound)
{
    int_fast32_t inv = 0;

    if (l_bound < r_bound)
    {
        //printf("mergeSort %zd, %zd\n", l_bound, r_bound);

        size_t middle = (l_bound + r_bound) / 2;

        inv += mergeSort(data, bfr, l_bound, middle);
        inv += mergeSort(data, bfr, middle+1, r_bound);
        inv += mergeInBuffer(data, bfr, l_bound, r_bound);
    }

    return inv;
}

int main()
{
    int_fast32_t* data = NULL;
    int_fast32_t* scratch = NULL;
    int_fast32_t inv = 0;
    size_t num_inp = 0;
    //get number of inputs
    scanf("%zu",&num_inp);

    //each input is two lines
    for (size_t prob=0; prob<num_inp; prob++)
    {
        size_t len = 0;
        //the first line containing the number of number in the 2nd line
        scanf("%zu",&len);
        data = malloc(len*sizeof(int_fast32_t));
        scratch = malloc(len*sizeof(int_fast32_t));

        //and the 2nd line containing an array of len integers to be sorted
        for (size_t i=0; i<len; i++)
        {
            scanf("%ld", &data[i]);
        }

        printArray(data, len);
        mergeSort(data, scratch, 0, len-1);
        printArray(data, len);
        printf("%ld\n", inv);
        if (data != NULL) { free(data); }
        if (scratch != NULL) { free(scratch); }
    }

    return 0;
}
