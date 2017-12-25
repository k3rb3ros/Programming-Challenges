#include <cassert>
#include <cmath>
#include <cstdint>
#include <climits>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

using namespace std;

typedef enum
{
    LEFT,
    RIGHT
} direction;

//c fast num_digits
int64_t num_digits(int64_t n)
{
    if (n < 0) n = (n == INT_MIN) ? INT_MAX : -n;
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    if (n < 1000000) return 6;
    if (n < 10000000) return 7;
    if (n < 100000000) return 8;
    if (n < 1000000000) return 9;
    if (n < 10000000000) return 10;
    if (n < 100000000000) return 11;
    if (n < 1000000000000) return 12;
    if (n < 10000000000000) return 13;
    if (n < 100000000000000) return 14;
    if (n < 1000000000000000) return 15;
    if (n < 10000000000000000) return 16;
    if (n < 100000000000000000) return 17;
    if (n < 1000000000000000000) return 18;

    //go to 19
    return 19;
}

int64_t split_digits(const int64_t num, const int64_t split, const direction dir)
{
    int num_dgts = num_digits(num);
    int split_dgts = -1;

    //split the digits into the left or right part
    if (num > 0 && split >= 0 && (dir == LEFT || dir == RIGHT))
    {
        stringstream ss;

        if (dir == LEFT)
        {
            if (split == 0) { split_dgts = 0; }
            else
            {
                ss << num;
                string dec_pre_split = ss.str();
                unique_ptr<uint8_t[]> dec_split(new uint8_t[split+1]());
                for (int s=0; s<split; ++s)
                {
                    dec_split[s] = dec_pre_split[s];
                }

                split_dgts = atol((char*)dec_split.get());
            }
        }
        else //dir == RIGHT
        {
            assert(dir == RIGHT);
            if (split == 0) { split_dgts = num; }
            else
            {
                ss << num;
                string dec_pre_split = ss.str();
                unique_ptr<uint8_t[]> dec_split(new uint8_t[num_dgts+1]());
                for (int s=split, t=0; s<num_dgts; ++s, ++t)
                {
                    dec_split[t] = dec_pre_split[s];
                }

                split_dgts = atol((char*)dec_split.get());
            }
        }
    }

    return split_dgts;
}

bool is_kaprekar_num(int num)
{
    bool success = false;

    if (num > 0)
    {
        const int64_t target = (int64_t)num * (int64_t)num; //calculate the square of num
        const int nd = num_digits(target);
        int split = nd/2; //start the split at the middle of the range
   
        int left = split_digits(target, split, LEFT);
        int right = split_digits(target, split, RIGHT);

        /* we are looking for a range of numbers in target that when split add up to
        * num
        */
        if ((left + right) == num)
        {
            success = true;
        }
    }

    return success;
}

void calc_kaprekars_in_range(int p, int q, vector<int> &found)
{
    for (int i=p; i<=q; ++i)
    {
        if (is_kaprekar_num(i))
        {
            found.push_back(i);
        }
    }
}

void display_results(vector<int> &found)
{
    if (found.size() == 0)
    {
        cout << "INVALID RANGE" << endl;
    }
    else
    {
        for (auto &i : found)
        {
            cout << i << " ";
        }
    }
}

int main(void)
{
    int p = 0;
    int q = 0;
    int status = -1;
    vector<int> kaprekar_numbers;

    cin >> p >> q;

    if (p < q && q < 100000)
    {
        calc_kaprekars_in_range(p, q, kaprekar_numbers);       
    }

    display_results(kaprekar_numbers);

    return status;
}
