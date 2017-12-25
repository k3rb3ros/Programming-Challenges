#include <iostream>
#include <fstream>
#include <stack>
#include <sstream>
#include <string>

#define TEAM "The wolfpack"
#define PROBLEM 1

using namespace std;

void solve_problem(string& str)
{
    cout << "Original string:" << str << endl;
    //we are going to use a stack to reverse the contents of the string
    stack<char> stack_;
    for (string::iterator it=str.begin(); it!=str.end(); ++it)
    {
        stack_.push(*it);
    }

    //allocate resources for the reverse string
    string rev(stack_.size(), '\0');

    //file the string in reverse from the stack
    for (size_t s=0; s<rev.size(); ++s)
    {
        rev[s] = stack_.top();
        stack_.pop();
    }

    cout << "Reversed string:" << rev << endl;
}

string get_string(ifstream& inp)
{
    stringstream ss;
    ss << inp.rdbuf();

    return ss.str();
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
            string str_to_rev = get_string(inf);
            solve_problem(str_to_rev);
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
