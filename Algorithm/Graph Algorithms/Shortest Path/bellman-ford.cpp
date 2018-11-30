// Bellman Ford Shortest Path ALgorithm for directed graphs
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <limits>
using namespace std;

void initialise(int *distance,int v){
	for(int i=1;i<=v;i++)
		distance[i] = numeric_limits<int>::max();
}

int main(void){
	int v;
	cout << "Enter number of vertices: ";
	cin >> v;
	int distance[v+1];
	initialise(distance,v);
	vector< pair<pair<int,int>,int> > graph;
	int e;
	cout << "Enter number of edges: ";
	cin >> e;
	cout << "Edges are: \n";
	for(int i=0;i<e;i++){
		int u,v,w;
		cin >> u >> v >> w;
		pair<pair<int,int>,int> element;	// <u,v> , w
		element = make_pair(make_pair(u,v),w);
		graph.push_back(element);
	}
	int src;
	cout << "Enter source vertex: ";
	cin >> src;
	distance[src] = 0;
	for(int i=1;i<=v-1;i++){
		for(int j=0;j<graph.size();j++){
			int u = graph[j].first.first;
			int v = graph[j].first.second;
			int w = graph[j].second;
			//cout << u << " " << v << " " << w << "\n";
			if(distance[v] > distance[u] + w and distance[u]!=numeric_limits<int>::max())
				distance[v] = distance[u] + w;
		}
	}
	cout << "Print the final distance vector: ";
	for(int i=1;i<=v;i++)
		cout << distance[i] << " ";
	cout << "\n";
	return 0;
}