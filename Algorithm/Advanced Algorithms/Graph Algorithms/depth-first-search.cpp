#include <iostream>
#include <vector>
#define MAX 100		// Maximum number of vertices in the graph possible
using namespace std;

class Graph{
	int v, e;		// Number of vertices and edges in graph
	vector<int> Adj[MAX];	// Adjacency List
	int color[MAX];		// Color for each vertex: white, gray, black
	int d[MAX], f[MAX];	// Discovery and finishing time
	int time;		// Global time counter
	public:
		Graph(int vertices, int edges){
			v = vertices;
			e = edges;
			
		}
};
