#include <iostream>
#include <climits>

using namespace std;

#define MAX_EDGES 100
#define MAX_VERTICES 10

void Bellman_Ford(int vertices, int edges, int src[], int destination[], int weight[], int source)
{
    int distance[MAX_VERTICES];

    // Initialize distances from source to all other vertices as infinite
    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;

    // Relax all edges (vertices - 1) times
    for (int i = 1; i <= vertices - 1; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            int u = src[j];
            int v = destination[j];
            int w = weight[j];

            if (distance[u] != INT_MAX && distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < edges; j++)
    {
        int u = src[j];
        int v = destination[j];
        int w = weight[j];

        if (distance[u] != INT_MAX && distance[u] + w < distance[v])
        {
            cout << "Graph contains a negative weight cycle!" << endl;
            return;
        }
    }

    // Print the shortest distances from the source
    cout << "Distance from Source (" << source << ")" << endl;
    for (int i = 0; i < vertices; i++)
    {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main()
{
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    int src[MAX_EDGES], destination[MAX_EDGES], weight[MAX_EDGES];

    cout << "Enter the edges as a matirx (source, destination, weight):" << endl;
    for (int i = 0; i < edges; i++)
    {
        cin >> src[i] >> destination[i] >> weight[i];
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    Bellman_Ford(vertices, edges, src, destination, weight, source);

    return 0;
}
