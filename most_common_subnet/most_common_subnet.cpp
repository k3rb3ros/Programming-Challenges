#include <iostream>
#include <fstream>
#include <stdint.h>
#include <string>

#define TEAM "The wolfpack"
#define PROBLEM 1

using namespace std;

struct 
{
    uint8_t oct1;
    uint8_t oct2;
    uint8_t oct3;
    uint8_t oct4;
    uint8_t addr_bits;
} ipv4_oct;

void solve_problem()
{
    cout << "Problem solving code goes here" << endl;
}

int main(int argc, char** argv)
{
    char in_fname[255] = { 0 };
    char out_fname[255] = { 0 };
    ifstream inf;
    ofstream outf;
    int status = 0;
    sprintf(in_fname, "prob%d.dat", PROBLEM);
    sprintf(out_fname, "prob%d.out", PROBLEM);

    inf.open(in_fname);
    if (inf != nullptr)
    {
        outf.open(out_fname);
        if (outf != nullptr)
        {
            solve_problem();
        }
        else
        {
            cout << "could not open output file " << out_fname << endl;
            status = -2;
        }
    }
    else
    {
        cout << "could not open input file " << in_fname << endl;
        status = -1;
    }

    inf.close();
    outf.close();

    return status;
}
