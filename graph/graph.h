#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

class graph{
    int v;
    int **adj;
    int weight;
    
public:
    graph(int v){
        this->v = v;
        adj = new int*[v];
        for(int r=0; r<v;r++){
            adj[r]=new int[v];
            for(int c=0;c<v;c++){
                adj[r][c]=0;
            }
        }
    }
    void addedge(int s ,int e){
        adj[s][e]=1;
        adj[e][s]=1;
    }
    
    void print(){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cout<<adj[i][j]<<" ";}
            cout<<endl;
        }
    }
};

class graphlist{
    int v;
    list<int> *l;
public:
    graphlist(int v){
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(vector <pair<int, int> > adj[], int u,
                                         int v, int wt)
    {
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }
     
    // Print adjacency list representation of graph
    void printGraph(vector<pair<int,int> > adj[], int V)
    {
        int v, w;
        for (int u = 0; u < V; u++)
        {
            cout << "Node " << u << " -> \n";
            for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
            {
                v = it->first;
                w = it->second;
                cout << "\tNode " << v << "  weight ="
                     << w << "\n";
            }
            cout << "\n";
        }
    }
     
};

