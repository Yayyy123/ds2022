#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "graph.h"

using namespace std;

int main(){
    graph g(5);//一共有多少点
    g.addedge(0, 1);
    g.addedge(0, 4);
    g.addedge(1, 2);
    g.addedge(1, 3);
    g.addedge(1, 4);
    g.addedge(2, 3);
    g.addedge(3, 4);
    g.print();
    
    cout<<endl;
        
    graphlist a(5);
    vector<pair<int, int> > adj[5];
    a.addEdge(adj, 0, 1, 10);
    a.addEdge(adj, 0, 4, 20);
    a.addEdge(adj, 1, 2, 30);
    a.addEdge(adj, 1, 3, 40);
    a.addEdge(adj, 1, 4, 50);
    a.addEdge(adj, 2, 3, 60);
    a.addEdge(adj, 3, 4, 70);
    a.printGraph(adj, 5);


    
    return 0;
    
}

