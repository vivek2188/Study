#include <iostream>
#include <vector>
#include <istream>
#include <ostream>
#include <algorithm>
#include <iterator>
#include <map>
#define MAX 100	  // Maximum number of vertices
using namespace std;

// Cost Matrix
int cost[MAX][MAX];
// Memo
map<pair<int,vector<int> >,pair<int,int> > next_index_value;

int G(int v,vector<int> V,int src){
	if(V.empty()){
		return cost[v][src];
	}
	// Avoiding recomputation
	if(next_index_value.find(make_pair(v,V))!=next_index_value.end())
		return next_index_value[make_pair(v,V)].second;

	int next_index = V[0];
	vector<int> copy_V(V.begin()+1,V.end());
	int MIN = cost[v][V[0]] + G(V[0],copy_V,src);
	for(int i=1;i<V.size();i++){
		copy_V = V;
		copy_V.erase(copy_V.begin()+i);
		int X = cost[v][V[i]] + G(V[i],copy_V,src);
		if(MIN>X){
		    MIN  = X;
		    next_index = V[i];
		}
	}
	next_index_value[make_pair(v,V)] = make_pair(next_index,MIN);
	return MIN;
}

int main(void){
	int v;
	cout << "Total number of vertices: ";
	cin >> v;
	int src;
	cout << "Source vertex: ";
	cin >> src;
	cout << "Cost Matrix: ";
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++)
			cin >> cost[i][j];
	}
	vector<int> V;
	for(int i=0;i<v;i++)
		if(i!=src)
	    	V.push_back(i);
	int min_cost = G(src,V,src);
	int j=src;
	cout << "Path: ";
	while(1){
	    cout << j+1 << " ";
	    if(V.empty()==true){
	    	cout << src+1 << "\n";
	    	break;
	    }
	    int next = next_index_value[make_pair(j,V)].first;
	    vector<int>::iterator itr = find(V.begin(),V.end(),next);
	    V.erase(itr);
	    j = next;
	}
	cout << "Minimum cost: " << min_cost << "\n";
	return 0;
}
