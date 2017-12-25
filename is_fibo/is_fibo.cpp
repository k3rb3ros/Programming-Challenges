#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdint.h>
using namespace std;

inline uint64_t nth_fibo(uint64_t n)
{
    if (n == 0) { return 0; }
    else if (n == 1) { return 1; }
    else if (n == 2) { return 2; }
    else
    {
        uint64_t fib = 0;
        uint64_t prev1 = 0;
        uint64_t prev2 = 1;
        uint64_t temp = 0;

        for (size_t s=3; s<=n; ++s)
        {
            temp = prev2;
            fib = prev1 + prev2;
            prev1 = temp;
            prev2 = fib;
        }

        return fib;
    }
}

inline bool is_fibo(uint64_t n)
{
    uint64_t count = 0;
    uint64_t fib = 0;

    do
    {
        fib = nth_fibo(count++);   
    }
    while(fib < n);

    return fib==n;
}

int main()
{
    //Get input
    if (cin)
    {
		bool  first = true;
        string line;
        while (getline(cin,line))
        {
			if (first) { first = false; } //first line in data file is number of lines
			else
			{
                uint64_t n = stoull(line);
                bool Is_fibo = is_fibo(n);

                if (Is_fibo)
                {
                    cout << "IsFibo" << endl;
                }
                else
                {
                   cout << "IsNotFibo" << endl;
                }
		    }
        }
    }
    else
    {
        cout << "Error no input to process" << endl;
    }

    return 0;
}
