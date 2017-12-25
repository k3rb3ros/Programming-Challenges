#include <exception>
#include <iostream>
#include <tuple>
#include <stdint.h>
#include <vector>

using namespace std;

inline bool sum_is_evenly_divisable(uint32_t k, uint32_t el1, uint32_t el2)
{
    return (el1 + el2) % k == 0;   
}

bool readInput(uint32_t& n, uint32_t& k, vector<uint32_t>& data)
{
    bool success = true;
    try
    {
        cin >> n >> k;
        uint32_t val = 0;;
        for (size_t i=0; i<n; ++i)
        {
            cin >> val;
            data.push_back(val);
        }
    }
    catch (exception& e)
    {
        cerr << "Invalid input" << endl;
        success = false;
    }

    return success;
}

/* Iterate through all possible pairs and push back any with evenly divisable pairs */
inline void push_evenly_div_pairs(uint32_t k, vector<uint32_t>& data, vector<pair<int, int>>& p)
{
    for (size_t s=0; s<data.size(); ++s)
    {
        for (size_t u=s; u<data.size(); ++u)
        {
            if (s!=u && sum_is_evenly_divisable(k, data[s], data[u]))
            {
                pair<int,int> P(data[s], data[u]);
                p.push_back(P);
            }
        }
    }
}

int main(int argc, char** argv)
{
    uint32_t n = 0;
    uint32_t k = 0;
    vector<uint32_t> data;
    vector<pair<int, int>> div_sum_pairs;

    readInput(n, k, data);
    push_evenly_div_pairs(k, data, div_sum_pairs);

    cout << div_sum_pairs.size() << endl;

    return 0;
}
