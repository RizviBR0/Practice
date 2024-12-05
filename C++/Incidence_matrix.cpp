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

    // Initialize the incidence matrix with zeros/ones
    int Incidence_Matrix[V + 1][E + 1];

    // Set all values in the incidence matrix to 0
    for (i = 1; i <= V; ++i)
    {
        for (j = 1; j <= E; ++j)
        {
            Incidence_Matrix[i][j] = 0;
        }
    }

    // Get the edges
    cout << "Enter the connected edges of u and v:" << endl;
    for (i = 1; i <= E; ++i)
    {

        cin >> u >> v;

        // Mark the corresponding entries in the incidence matrix
        Incidence_Matrix[u][i] = 1;
        Incidence_Matrix[v][i] = 1;
    }

    // Output the incidence matrix
    cout << "The incidence matrix is:" << endl;
    for (i = 1; i <= V; ++i)
    {
        for (j = 1; j <= E; ++j)
        {
            cout << Incidence_Matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}