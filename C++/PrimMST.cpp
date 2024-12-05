#include <iostream>
#include <climits>
using namespace std;
#define MAX 200

int Min_Key(bool mst_V_Set[], int key[], int vertices)
{
    int min = INT_MAX, min_vertex;
    for (int i = 0; i < vertices; i++)
    {
        if (!mst_V_Set[i] && key[i] < min)
        {
            min = key[i];
            min_vertex = i;
        }
    }
    return min_vertex;
}

void prim_MST(int graph[MAX][MAX], int vertices)
{
    int parent[MAX];     // parent[i] stores the MST edges
    int key[MAX];        // holds the minimum weight edge that connects vertex i to the MST.
    bool mst_V_Set[MAX]; // To represent set of vertices included in MST

    for (int i = 0; i < vertices; i++)
    {
        key[i] = INT_MAX;
        mst_V_Set[i] = false;
    }

    // Start from the first vertex
    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < vertices - 1; i++)
    {
        int u = Min_Key(mst_V_Set, key, vertices);
        mst_V_Set[u] = true;

        // Update key and parent index of adjacent vertices
        for (int v = 0; v < vertices; v++)
        {
            if (graph[u][v] && !mst_V_Set[v] && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print MST
    cout << "Edges in the Minimum Spanning Tree (Prim's Algorithm):" << endl;
    int total_Weight = 0;
    for (int i = 1; i < vertices; i++)
    {
        cout << parent[i] << " - " << i << " : " << graph[parent[i]][i] << endl;
        total_Weight += graph[parent[i]][i];
    }
    cout << "Total Weight of MST: " << total_Weight << endl;
}

int main()
{
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    int graph[MAX][MAX];
    cout << "Enter the adjacency matrix of weight (0 if no edge):" << endl;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> graph[i][j];
        }
    }

    prim_MST(graph, vertices);

    return 0;
}
