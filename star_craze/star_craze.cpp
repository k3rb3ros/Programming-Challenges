#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

#define PROBLEM 0

using namespace std;

//we represent our graph as a list of edges associated with a vertex
typedef struct 
{
    int id = 0;
    bool full = false;
    vector<int> edges;
}node;

class graph
{
    private:
    map<int, node> nodes;

    bool isFilled(int node_)
    {
        bool filled = false;
        auto lookup = nodes.find(node_);

        if (lookup != nodes.end())
        {
            node N = nodes[node_];
            filled = N.full;
        }

        return filled;
    }

    //returns the first unfilled edge or -1 on failure
    int lowestEmptyNeighbor(int node_)
    {
        int edge = -1;
        auto lookup = nodes.find(node_);

        if (lookup != nodes.end())
        {
            node N = nodes[node_];
            for (auto i : N.edges)
            {
                if (!isFilled(i))
                {
                    edge = i;
                    break;
                }
            }
        }

        return edge;
    }

    bool winCondition()
    {
        size_t count = 0;

        for (auto it : nodes)
        {
            if (get<1>(it).full) { count++; }
        }

        return (count == nodes.size()-1);
    }

    bool fillNode(int node_)
    {
        bool success = false;

        auto lookup = nodes.find(node_);
        if (lookup != nodes.end())
        {
            nodes[node_].full = true;
        }

        return success;
    }

    void reset()
    {
        for (auto &it : nodes)
        {
            node N = get<1>(it);
            N.full = true;
        }
    }

    public:
    //default ctor
    graph() : nodes() { /* nop */}

    bool insertNode(int vertex, vector<int> edges)
    {
        bool success = false;

        //check if vertex doesn't already exist if it doesn't insert it otherwise fail
        if (nodes.find(vertex) == nodes.end())
        {
            node N;
            N.id = vertex;
            N.edges = edges;
            nodes[N.id] = N;
            success = true;
        }

        return success;
    }

    bool solveProblem(int start_at=1)
    {
        cout << "Starting at " << start_at << endl;

        if (nodes.find(start_at) != nodes.end())
        {
            int node = lowestEmptyNeighbor(start_at);
            fillNode(start_at);

            //traverse and fill until you can no longer
            while (node != -1)
            {
                if (!isFilled(node))
                {
                    fillNode(node);
                }
                node = lowestEmptyNeighbor(node);
            }
        }

        //determine if we won
        bool win = winCondition();
        //reset the graph
        reset();

        if (win) { cout << "Win" << endl; } 
        else { cout << "Loss" << endl; }

        return win;
    }

    size_t size()
    {
        return nodes.size();
    }

    void printGraph()
    {
        cout << "Graph" << endl;
        cout << "{" << endl;
        for (auto it : nodes)
        {
            node N = get<1>(it);
            cout << "\tNode: " << N.id << " filled: " << N.full << " edges: ";
            for (auto e : N.edges)
            { 
                cout << e;
                if (e != N.edges[N.edges.size()-1]) { cout << ", "; } 
            } 
            cout << endl;
        }
        cout << "}" << endl;
    }
};

bool parse_line(string &line, graph &G)
{
    bool success = false;

    //a valid line must have at least a vertex
    if (line.size() > 1)
    {
        istringstream iss(line);
        int node;
        vector<int> edges;

        iss >> node;
        while (iss && !iss.eof())
        {
            int edge = 0;
            iss >> edge;
            edges.push_back(edge);
        }

        success = G.insertNode(node, edges);
    }

    return success;
}

bool read_data_into_graph(ifstream &outf, graph &G)
{
    bool success = true;
    string line;

    while (outf && success)
    {
        getline(outf, line);
        if (line.size() > 1)
        {
            success = parse_line(line, G);
        }
    }

    return success;
}

int main(int argc, char** argv)
{
    char in_fname[255] = { 0 };
    char out_fname[255] = { 0 };
    graph G;
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
            vector<uint32_t> solutions;
            if (read_data_into_graph(inf, G))
            {
                for (size_t s=1; s<=G.size(); ++s)
                {
                    if (G.solveProblem(s))
                    {
                        G.printGraph();
                        solutions.push_back(s);
                    }
                }
            }

            if (solutions.size() > 0)
            {
                cout << "It is possible to win through niave traversal starting at: ";
                for (auto s : solutions)
                {
                    cout << s;
                    if (s < solutions.size()-1) { cout << ", "; }
                }
                cout << endl;
            }
            else
            {
                cout << "No solutions through niave traversal exists" << endl;
            }
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
