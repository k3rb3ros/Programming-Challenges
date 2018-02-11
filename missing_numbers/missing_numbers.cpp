#include <stdint.h>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

class NumberMatcher
{
    map<uint64_t, uint32_t> _aCount;
    map<uint64_t, uint32_t> _bCount;
    map<uint64_t, bool> _solution;

    public: NumberMatcher(vector<uint64_t>* a, vector<uint64_t>* b)
    {
        if (a != nullptr && b != nullptr)
        {
            for (auto const &it : *a)
            {
                if (_aCount.find(it) != _aCount.end())
                {
                    _aCount[it] ++;
                }
                else
                {
                    _aCount[it] = 1;
                }
            }

            for (auto const &it : *b)
            {
                if (_bCount.find(it) != _bCount.end())
                {
                    _bCount[it] ++;
                }
                else
                {
                    _bCount[it] = 1;
                }
            }
        }
    }

    ~NumberMatcher()
    {
    }

    public: void Output()
    {
        if (_solution.size() > 0)
        {
            for (auto const &it : _solution)
            {
                cout << it.first << " ";
            }
        }
    }

    public: void Solve()
    {
        // check for diffs in map A
        for (auto const &it : _aCount)
        {
            // number in A not in B
            if (_bCount.find(it.first) == _bCount.end())
            {
                _solution[it.first] = true;
            }
            // number in A and B but count differs
            else if (_bCount.find(it.first) != _bCount.end())
            {
                if (_bCount[it.first] != it.second)
                {
                    _solution[it.first] = true;
                }
            }
        }
        // check for numbers in map B not in A
        for (auto const &it : _bCount)
        {
            if (_aCount.find(it.first) == _aCount.end() && _solution.find(it.first) == _solution.end())
            {
                _solution[it.first] = true;
            }
        }
    }
};

int main(int argc, char** argv)
{
    uint64_t sizeA = 0;
    uint64_t sizeB = 0;

    cin >> sizeA;
    vector <uint64_t> A(sizeA);

    for (auto it=A.begin(); it!=A.end(); ++it)
    {
        uint64_t valA = 0;
        cin >> valA;
        *it = valA;
    }
   
    cin >> sizeB; 
    vector <uint64_t> B(sizeB);

    for (auto it=B.begin(); it!=B.end(); ++it)
    {
        uint64_t valB = 0;
        cin >> valB;
        *it = valB;
    }

    NumberMatcher nm(&A, &B);
    nm.Solve();
    nm.Output();

    return 0;
}
