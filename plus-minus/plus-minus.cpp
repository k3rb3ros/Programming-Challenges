#include <cstdint> //uintxx_t
#include <iomanip> //setprecision
#include <iostream> //cin, cout, endl
#include <vector> //vector

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::vector;

int main(void)
{
    size_t num_inputs = 0;

    cin >> num_inputs;

    int_fast32_t positive = 0; 
    int_fast32_t negative = 0;
    int_fast32_t zed = 0;
    size_t inp_size = 0;

    for (size_t i=0; i<num_inputs; ++i)
    {
        inp_size++;
        int_fast32_t val = 0;
        cin >> val;
        //keep track of +,- and zero values
        if (val > 0) { ++positive; }
        else if (val == 0) { ++zed; }
        else { ++negative; }

    }

    double pos_rat = (double)positive/(double)inp_size;
    double neg_rat = (double)negative/(double)inp_size;
    double zed_rat = (double)zed/(double)inp_size;

    cout << fixed << setprecision(6);
    cout << pos_rat << endl;
    cout << neg_rat << endl;
    cout << zed_rat << endl;

    return 0;
}
