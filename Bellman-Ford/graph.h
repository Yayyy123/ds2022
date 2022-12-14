#include <iostream>
using namespace std;

// 表示图中加权边的结构
struct Edge {
    int src, dest, weight;
};

// 表示连接的、有向的和
struct Graph {
    // V->顶点数，E->边数
    int V, E;

    //图表示为边数组
    struct Edge* edge;
};

//创建一个有 V 个顶点和 E 个边的图
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

// A utility function used to print the solution
void printArr(int dist[], int n)
{
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}


// 寻找到 src 的最短距离的主函数
// 使用 Bellman-Ford 算法到所有其他顶点。这
// 函数还检测负权重循环
void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    // 第 1 步：初始化从 src 到所有其他的距离
    // 顶点为 INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    
    // 第 2 步：放松所有边 |V| - 1 次。一个简单的
    // 从 src 到任何其他顶点的最短路径可以有
    // 至多 |V| - 1 条边
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX
                && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // 第 3 步：检查负权重循环。以上
    // step 保证最短距离，如果图形不
    // 包含负权重循环。如果我们得到更短的
    // 路径，则有循环。
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX
            && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle");
            return; 
        }
    }

    printArr(dist, V);

    return;
}
