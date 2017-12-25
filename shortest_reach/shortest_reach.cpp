#include <exception>
#include <iostream>
#include <map>
#include <queue>
#include <stdint.h>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

//            node      weight
typedef tuple<uint64_t, uint64_t> vertex;

struct graph_node
{
  vertex Vertex;
  vector<graph_node*> Links;
};

//          node      node and links
typedef map<uint64_t, graph_node> undirected_graph;

//            node1     node2     weight 
typedef tuple<uint64_t, uint64_t, uint64_t> edge;

typedef vector<edge> edge_list;

//define comparison of vertex's by weight
struct CompGraphNode
{
    bool operator() (const graph_node &a, const graph_node &b) const
    {
        return get<1>(a.Vertex) > get<1>(b.Vertex);
    }
};
struct CompGraphNodePtr
{
    bool operator() (const graph_node* a, const graph_node* b) const
    {
        return get<1>(a->Vertex) > get<1>(b->Vertex);
    }
};

class shortestReach
{
    public:

    /***************
     * Constructor *
     **************/
    shortestReach(uint64_t edge_weight)
    {
        //Load the test case from input data on instantiation of the class

        //the first line contains the number of nodes and edges
        cin >> m_num_nodes >> m_num_edges;

        //followed by a line for every edge containg the two nodes linked by the edge
        for (size_t s=0; s<m_num_edges; ++s)
        {
            uint64_t first = 0;
            uint64_t second = 0;

            cin >> first >> second;
            edge E(first, second, edge_weight);
            m_edges.push_back(E);
        }

        /*
         * Init the graph with a with a map for every node
         * this allows us to create pointers to them before they are populated
         */
        for (size_t s=1; s<=m_num_nodes; ++s)
        {
            graph_node G;
            //Init the vertex
            vertex V(s, edge_weight);
            G.Vertex = V;
            //Init the linked vertex list
            initLinkList(G.Links, m_num_nodes+1);

            //Init the graph with all nodes without links
            m_graph[s] = G;
        }

        //populate the links in the graph
        for (size_t s=1; s<=m_num_nodes; ++s)
        {
            graph_node G = m_graph[s];
            //get the links we are updating
            for (auto e : m_edges)
            {
                int64_t link = getLink(s, e);
                if (link != -1)
                {
                    G.Links[link] = &(m_graph[link]);
                } 
            }

            //update the graph node
            m_graph[s] = G;
        }

        //Get the node to start the shortest path search from
        cin >> m_starting_node;
    }
    
    bool run()
    {
        bool success = true;
        vector<uint64_t> D(m_graph.size()+1);

        try
        {
            for (size_t s=1; s<=m_num_nodes; ++s)
            {
                if (s != m_starting_node)
                {
                    if (dijkstra(m_starting_node, s, D))
                    {
                        cout << shortest_path(D, s) << " ";
                    }
                    else
                    {
                        cout << "-1 ";
                    }
                }
            }
            cout << endl;
        }
        catch (exception e)
        {
            success = false;
            cerr << e.what() << endl;
        }

        return success;
    }

    //Print the details of the graph
    void printGraph(string message = "")
    {
        if (m_edges.size() > 0)
        {
            cout << "Graph ";
            if (message.compare("") != 0) { cout << message << " "; }
            cout << "Nodes:" << m_num_nodes << " Edges:{";
            for (size_t s=0; s<m_edges.size(); ++s)
            {
                auto Edge = m_edges[s];
                cout << "(" << get<0>(Edge) << "," << get<1>(Edge)
                     << ",W" << get<2>(Edge) <<")";
                

                if (s < (m_edges.size()-1))
                {
                    cout << ", ";
                }
            }
            cout << "} Starting Node:" << m_starting_node << endl;

            for (auto &N : m_graph)
            {
                cout << get<0>(N.second.Vertex) << ":[";
                for (size_t s=1; s<=m_num_nodes; ++s)
                {
                    if (N.second.Links[s] == nullptr) { cout << "X"; }
                    else { cout << get<0>(N.second.Links[s]->Vertex); }

                    if (s != m_num_nodes) { cout << ","; }
                }
                cout << "]" << endl;
            }
        }
        else
        {
            cerr << "No graph loaded to print" << endl;
        }
    }

    void printGraphInfo()
    {
        cout << "Nodes: " << m_num_nodes << " Edges: " << m_edges.size();
    }

    private:

    /****************
     * private data *
     ***************/
    size_t m_num_nodes = 0;
    size_t m_num_edges = 0;
    edge_list m_edges;
    undirected_graph m_graph;
    uint64_t m_starting_node = 0;

    /*******************
     * private methods *
     ******************/
    
    bool dijkstra(const uint64_t start, const uint64_t target,
                  vector<uint64_t> &dist)
    {
        //Initialization
        bool tgt_found = false;
        priority_queue<graph_node*, vector<graph_node*>, CompGraphNodePtr> Q;
        vector <uint64_t> P;
        graph_node* S = &m_graph[start];
        get<1>(S->Vertex) = 0;
        initVector(dist, UINTMAX_MAX);
        dist[start] = 0;
        P.push_back(start);
        Q.push(S);

        while (!Q.empty())
        {
            //Get the highest priority node in the Q
            graph_node* U = Q.top();
            Q.pop();

            //for each neighbor of U
            for (size_t s=1; s<=m_num_nodes; ++s)
            {
                graph_node* V = U->Links[s];

                if (V != nullptr)
                {

                    uint64_t D = (dist[get<0>(U->Vertex)] == UINTMAX_MAX) ? 0 : dist[get<0>(U->Vertex)];
                    uint64_t alt = D + get<1>(V->Vertex);
                    uint64_t dist_v = dist[s];

                    if (alt < dist_v)
                    {
                        dist[s] = alt;
                        P.push_back(get<0>(V->Vertex));
                        if (get<0>(V->Vertex) == target)
                        { 
                            tgt_found = true;
                            break; 
                        }
                        Q.push(V);
                    }
                }
            } /* end for */
        } /* end while */

        return tgt_found;
    }

    int64_t shortest_path(const vector<uint64_t> &D, uint64_t tgt) const
    {
        int64_t SP = -1;

        if (tgt < D.size())
        {
            SP = D[tgt];
        }

        return SP;
    }

    //return the node of an edge linked to the node passed in (if it exists)
    inline int64_t getLink(const size_t node, const edge& e) const
    {
        int64_t link = -1;

        if (get<0>(e) == node)
        {
            link = get<1>(e);
        }
        else if (get<1>(e) == node)
        {
            link = get<0>(e);
        }

        return link;
    }

    //Initialize a list of vertex pointers to nullptr
    inline void initLinkList(vector<graph_node*> &L, size_t size)
    {
        for (; size>0; --size)
        {
            L.push_back(nullptr);
        }
    }

    inline void initVector(vector<uint64_t> &V, uint64_t val)
    {
        for (auto &v : V) { v = val; }
    }
};

int main(int argc, char** argv)
{
    //Get the number of test Cases
    size_t Q = 0;
    cin >> Q;

    //Load and then run each test case
    for (size_t s=0; s<Q; ++s)
    {
        shortestReach S(6);
        S.run();
    }

    return 0;
}
