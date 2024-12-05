#include <iostream>
#include <stack>

using namespace std;

void DFS(int graph[][100], int start_vertex, int vertices)
{
    bool visited_vertex[vertices + 1];
    stack<int> s;

    // Initialize all vertices as not visited
    for (int i = 1; i <= vertices; i++)
    {
        visited_vertex[i] = false;
    }

    // Push the start vertex onto the stack
    s.push(start_vertex);

    while (!s.empty())
    {
        // Pop a vertex from the stack
        int current_vertex = s.top();
        s.pop();

        // If the vertex hasn't been visited yet
        if (!visited_vertex[current_vertex])
        {
            cout << current_vertex << " ";         // Print the vertex
            visited_vertex[current_vertex] = true; // Mark it as visited
        }

        // Get all adjacent vertices of the current vertex
        // If an adjacent vertex hasn't been visited, push it onto the stack
        for (int i = vertices; i >= 1; i--)
        {
            if (graph[current_vertex][i] == 1 && !visited_vertex[i])
            {
                s.push(i);
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

    // Get the edges from the user and populate the adjacency matrix
    cout << "Enter the edges (u v) where u and v are the vertices connected by an edge:" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // comment this line if the graph is directed
    }

    int start_vertex;
    cout << "Enter the starting vertex: ";
    cin >> start_vertex;

    // Perform DFS
    cout << "DFS traversal starting from vertex " << start_vertex << ": ";
    DFS(graph, start_vertex, vertices);

    return 0;
}
