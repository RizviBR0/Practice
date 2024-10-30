#include <iostream>
using namespace std;

int i, j, u, v, V, E, input;

int vertexAndEdgeInput()
{
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;
}

void directed(int V, int E)
{
    int Adjacent_Matrix[V + 1][V + 1];

    for (i = 0; i <= V; ++i)
    {
        for (j = 1; j <= V; ++j)
        {
            Adjacent_Matrix[i][j] = 0;
        }
    }

    cout << "Enter the connected edges of u and v: " << endl;
    for (i = 1; i <= E; ++i)
    {
        cin >> u >> v;

        Adjacent_Matrix[u][v] = 1;
    }

    cout << "Adjacent Matrix: " << endl;
    for (i = 1; i <= V; ++i)
    {
        for (j = 1; j <= V; ++j)
        {
            cout << Adjacent_Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void undirected(int V, int E)
{
    int Adjacent_Matrix[V + 1][V + 1];

    for (i = 0; i <= V; ++i)
    {
        for (j = 1; j <= V; ++j)
        {
            Adjacent_Matrix[i][j] = 0;
        }
    }

    cout << "Enter the connected edges of u and v: " << endl;
    for (i = 1; i <= E; ++i)
    {
        cin >> u >> v;

        Adjacent_Matrix[u][v] = 1;
        Adjacent_Matrix[v][u] = 1;
    }

    cout << "Adjacent Matrix: " << endl;
    for (i = 1; i <= V; ++i)
    {
        for (j = 1; j <= V; ++j)
        {
            cout << Adjacent_Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "------------------\n1. Directed graph\n2. Undirected graph\n------------------" << endl;
    cout << "Enter your choice: ";
    cin >> input;

    switch (input)
    {
    case 1:
        vertexAndEdgeInput();
        directed(V, E);
        break;

    case 2:
        vertexAndEdgeInput();
        undirected(V, E);
        break;

    default:
        cout << "Invalid choice!" << endl;
        break;
    }
}