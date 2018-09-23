#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

vector<int>G[MAX];

void dfs(){
}

int  main(){
	int v,e;
	cin >> v >> e;
	while(e--){
		int s,d;
		cin >> s >> d;
		G[s].push_back(d);
	}
	dfs();
	return 0;
}
