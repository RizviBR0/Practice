#include <iostream>
#include <queue>

using namespace std;

void BFS(int graph[100][100], int start_vertex, int vertices)
{

    int visited_vertex[vertices + 1];

    queue<int> q;

    // Initialize all vertices as not visited
    for (int i = 1; i <= vertices; i++)
    {
        visited_vertex[i] = 0;
    }

    // Mark the start vertex as visited and enqueue it
    visited_vertex[start_vertex] = 1;
    q.push(start_vertex);

    while (!q.empty())
    {
        // Dequeue a vertex from the queue and print it
        int current_vertex = q.front();
        cout << current_vertex << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex hasn't been visited, mark it visited and enqueue it
        for (int i = 1; i <= vertices; i++)
        {
            if (graph[current_vertex][i] == 1 && !visited_vertex[i])
            {
                visited_vertex[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int vertices, edges;
    int graph[100][100];

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    // Initialize the adjacency matrix with zeros
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    // Get the edges from to form the adjacency matrix
    cout << "Enter the edges between u  and v:" << endl;
    for (int i = 1; i <= edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start_vertex;
    cout << "Enter the starting vertex: ";
    cin >> start_vertex;

    // Perform BFS
    cout << "BFS traversal starting from vertex " << start_vertex << ": ";
    BFS(graph, start_vertex, vertices);

    return 0;
}
