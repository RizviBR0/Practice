#include<iostream>
#include<climits>
using namespace std;

#define MAX 100

int minimumDist(int dist[], bool Tset[], int vertices)
{
	int min=INT_MAX;
	int index=-1;

	for(int i=0;i<vertices;i++)
	{
		if(Tset[i]==false && dist[i]<min)
		{
			min=dist[i];
			index=i;
		}
	}
	return index;
}

void Dijkstra(int graph[MAX][MAX],int source, int vertices)
{
	int dist[MAX]; // integer array to calculate minimum distance for each node.
	bool Tset[MAX];// boolean array to mark visted/unvisted for each node.

	// set the nodes with infinity distance
	// except for the initial node and mark
	// them unvisited.
	for(int i = 0; i<vertices; i++)
	{
		dist[i] = INT_MAX;
		Tset[i] = false;
	}

	dist[source] = 0;   // Source vertex distance is set to zero.

	for(int i = 0; i<vertices-1; i++)
	{
		int m=minimumDist(dist,Tset,vertices); // vertex not yet included.
		Tset[m]=true;// m with minimum distance included in Tset.
		for(int i = 0; i<vertices; i++)
		{
			// Updating the minimum distance for the particular node.
			if(!Tset[i] && graph[m][i] && dist[m]!=INT_MAX && dist[m]+graph[m][i]<dist[i]){
				dist[i]=dist[m]+graph[m][i];
		}
	}

	}

	cout<<"Vertex\t\tDistance from source"<<endl;
	for(int i = 0; i<vertices; i++)
	{
		cout<<i<<"\t\t\t"<<dist[i]<<endl;
	}
}


int main() {
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    int graph[MAX][MAX];
    cout << "Enter the adjacency matrix (use 0 for no edge):" << endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cin >> graph[i][j];
        }
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    Dijkstra(graph, source, vertices);

return 0;
}
