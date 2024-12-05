#include <iostream>
using namespace std;

int main()
{
    int V, E;
    int i, j, u, v;

    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;
    // Initialize the adjacency matrix with zeros/ones
    int Adjacent_Matrix[V + 1][V + 1];
    // Set all values in the adjacency matrix to 0
    for (i = 1; i <= V; ++i)
    {
        for (j = 1; j <= V; ++j)
        {
            Adjacent_Matrix[i][j] = 0;
        }
    }
    // Enter the edges
    cout << "Enter the connected edges of u and v:" << endl;
    for (i = 1; i <= E; ++i)
    {
        cin >> u >> v;
        // Confirm the corresponding entries in the adjacency matrix (directed/indirected?)
        Adjacent_Matrix[u][v] = 1;
        Adjacent_Matrix[v][u] = 1;
    }
    // Displaying Output of the the adjacency matrix
    cout << "The Adjacency Matrix is:" << endl;
    for (i = 1; i <= V; ++i)
    {
        for (j = 1; j <= V; ++j)
        {
            cout << Adjacent_Matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
