#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdint.h>
using namespace std;


int main()
{
    uint64_t n;
    cin >> n;
    uint64_t sum = 0;

    for (size_t s=0; s<=n; ++s)
    {
        uint64_t num = 0;
        cin >> num;
        sum += num;
    }

    cout << sum << endl;

    return 0;
}

