#include <iostream>
#include <queue>
using namespace std;

void dfs(int s, vector<int> g[], bool vis[]){
    vis[s] = true;
    cout << s << " ";
    for(int i=0;i<g[s].size();i++){
        if(!vis[g[s][i]])
            dfs(g[s][i],g,vis);
    }
}

void bfs(int s,vector<int> adj[],bool vis[]){
    queue<int>q;
    vis[s] = true;
    q.push(s);
    while(!q.empty()){
        cout << q.front() << " ";
        int k = q.front();
        q.pop();
        for(int i=0;i<g[k].size();i++){
            if(!vis[g[k][i]]){
                q.push(g[k][i]);
                vis[g[k][i]] = true;   
            }
        }
    }
}