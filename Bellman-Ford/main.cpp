#include <iostream>
#include "graph.h"
using namespace std;


int main()
{
  
    int V = 5; // 顶点数
    int E = 8; // 边数
    struct Graph* graph = createGraph(V, E);

    graph->edge[0].src = 0; //从点1
    graph->edge[0].dest = 1;//去点2
    graph->edge[0].weight = -6;//权重为

    graph->edge[1].src = 0;//从点1
    graph->edge[1].dest = 2;//去点3
    graph->edge[1].weight = 7;//权重

    graph->edge[2].src = 1;//从点2
    graph->edge[2].dest = 2;//去点3
    graph->edge[2].weight = 8;//权重

    graph->edge[3].src = 1;//从点2
    graph->edge[3].dest = 3;//去点4
    graph->edge[3].weight = 8;//权重

    graph->edge[4].src = 1;//从点2
    graph->edge[4].dest = 4;//去点5
    graph->edge[4].weight = -5;//权重

    graph->edge[5].src = 3;//从点4
    graph->edge[5].dest = 2;//去点3
    graph->edge[5].weight = 6;//权重

    graph->edge[6].src = 3;//从点4
    graph->edge[6].dest = 1;//去点2
    graph->edge[6].weight = 9;//权重

    graph->edge[7].src = 4;//从点5
    graph->edge[7].dest = 3;//去点4
    graph->edge[7].weight = 4;//权重
    
    BellmanFord(graph, 3);

    return 0;
}
