#include <exception>
#include <iostream>
#include <map>
#include <stdint.h>
#include <vector>

using namespace std;

typedef vector<int_fast64_t> data_set;

class testCase
{
    public:

    /***************
     * Constructor *
     **************/
    /*testCase()
    {
    }*/

    /**************
     * Destructor *
     *************/
    ~testCase()
    {
        if (m_data != nullptr)
        {
            delete m_data;
            m_data = nullptr;
        }
    }

    /******************
     * public methods *
     *****************/
    bool loadCase()
    {
        bool success = true;

        try
        {
            //all cases begin with a line telling us how many integers are on the next line
            size_t N = 0;
            cin >> N;
            if (N > 0)
            {
                int_fast64_t val = 0;
                m_data = new data_set(N);

                for (size_t s=0; s<N; ++s)
                {
                    cin >> val;
                    m_data->at(s) = val;

                    //keep track of the min and max values
                    if (val < m_min) { m_min = val; }
                    if (val > m_max) { m_max = val; }
                }
            }
        }
        catch (exception e)
        {
            success = false;
            cerr << e.what() << endl;
        }

        return success;;
    }
  
    //The REAL problem occurs here
    int_fast64_t getContMax()
    {
        return maxSubArray();
    }

    int_fast64_t getNonContMax()
    {
        int_fast64_t max = 0;
        /*if no negative numbers are present the max subarray is the full array so we sum the
         * full number set
         */
        if (!hasNegative() )
        {
            max = sumRange(0, m_data->size()-1);
        }
        /* if positive numbers are present then the max non contiguous sub array is the sum
         * of the subarray containing all positive values
         */
        else if (hasPositive() && hasNegative())
        {
            for (auto &v : *m_data)
            {
                if (v > 0) { max += v; }
            }
        }
        /*all negative values so the max is subarray of size 1 of the smallest negative value
         */
        else
        {
            max = m_max;
        }

        return max;
    }

    void printCase()
    {
        if (this->m_data != nullptr)
        {
            for (data_set::iterator it=m_data->begin(); it != m_data->end(); ++it)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
        else
        {
            cerr << "Test case not loaded cannot print" << endl;
        }
    }

    private:
    /************************
     * private data members *
     ***********************/
    int_fast64_t m_min = INTMAX_MAX;
    int_fast64_t m_max = INTMAX_MIN;

    data_set* m_data = nullptr;

    /*******************
     * private methods *
     ******************/

    inline bool hasNegative()
    {
        return this->m_min < 0;
    }

    inline bool hasPositive()
    {
        return this->m_max > 0;
    }

    inline int_fast64_t max(int_fast64_t a, int_fast64_t b)
    {
        return (a >= b) ? a : b;
    }

    inline int_fast64_t sumRange(size_t ind1, size_t ind2)
    {
        int_fast64_t sum = 0;
        if (m_data != nullptr && m_data->size() > 0 &&
            ind1 < m_data->size() && ind2 < m_data->size())
        {
            for (size_t s=ind1; s<= ind2; ++s)
            {
                sum += m_data->at(s);
            }
        }

        return sum;
    }

    /*This is where all the special sauce is I just wish it took me less time
     * to figure out there was a recursive solution
     */
    int_fast64_t maxSubArray()
    {
        int_fast64_t Max = 0;

        if (m_data != nullptr && m_data->size() > 0)
        {
            int_fast64_t max_here = m_data->at(0);
            int_fast64_t max_so_far = m_data->at(0);

            for (size_t s=1; s<=m_data->size()-1; ++s)
            {
                max_here = max(m_data->at(s), (max_here + m_data->at(s)));
                max_so_far = max(max_so_far, max_here);
            }

            Max = max_so_far;
        }

        return Max;
    }
};

int main(int argc, char** argv)
{
    //the first line of input tells us how many input cases will follow
    size_t T = 0;
    cin >> T;

    for (size_t s=0; s<T; ++s)
    {
        testCase C;

        if (C.loadCase())
        {
            //C.printCase();
            cout << C.getContMax() << " " << C.getNonContMax() << endl;
        }
    }

    return 0;
}
