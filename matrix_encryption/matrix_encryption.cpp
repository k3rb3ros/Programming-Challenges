#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>
using namespace std;

static unique_ptr<uint8_t[]> gen_matrix(const string &inp)
{
    
    const size_t rows = ceil(sqrt(inp.size()));
    const size_t columns = ceil(sqrt(inp.size()));

    assert(rows*columns >= inp.size());
    return unique_ptr<uint8_t[]>(new uint8_t[rows*columns]());
}

static bool populate_matrix(const string &inp, unique_ptr<uint8_t[]> &mtrx,
                            const size_t cols, const size_t rows)
{
    bool success = false;

    if (rows > 0 && cols > 0)
    {
        for (size_t s=0; s<inp.size(); ++s)
        {
            mtrx.get()[s] = inp[s];
        }
        success = true;
    }

    return success;
}

static bool get_columns(const unique_ptr<uint8_t[]> &mtrx,
                        const size_t str_size, const size_t cols, const size_t rows,
                        vector<string> &col_strs)
{
    bool success = false;

    if (rows > 0 && cols > 0)
    {
        for (size_t C=0; C<cols; ++C)
        {
            stringstream ss;
            for (size_t R=0; R<rows; ++R)
            {
                //iterate through the byte array as a column wise 2d matrix
                uint8_t ch = mtrx.get()[C+(R*cols)];
                if (ch != '\0') { ss << ch; }
            }
            col_strs.push_back(ss.str());
        }

        success = true;
    }
        
    return success;
}

int main()
{
    string inp;

    //read input
    cin >> inp;

    unique_ptr<uint8_t[]> matrix = gen_matrix(inp);
    const uint64_t rows = ceil(sqrt(inp.size()));
    const uint64_t columns = ceil(sqrt(inp.size()));

    matrix = gen_matrix(inp);
    if (populate_matrix(inp, matrix, columns, rows))
    {
       vector<string> col_strs;
       if (get_columns(matrix, inp.size(), columns, rows, col_strs))
       {
           for (auto &c : col_strs)
           {
               cout << c << " ";
           }
           cout << endl;
       } 
    }
    else 
    {
        cerr << "ERROR populating matrix" << endl;
    }

    return 0;
    }
