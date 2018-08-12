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

bool dfs_cycle(int,list<int>*,int[]);
bool Graph :: isCyclic(){
    int vis[V];
    for(int i=0;i<V;i++)
        vis[i] = 0;
    bool flag = 0;
    list<int>* g = adj;
    for(int i=0;i<V and !flag;i++){
        if(vis[i]==0)
            flag = dfs_cycle(i,g,vis);
    }
    return flag;
}

bool dfs_cycle(int s,list<int>*g,int vis[]){
    vis[s] = 1;
    bool flag = 0;
    for(auto i=g[s].begin();i!=g[s].end() and !flag;i++){
        if(vis[*i]==0)
            flag = (flag|dfs_cycle(*i,g,vis));
        else if(vis[*i]==1)
            return 1;
    }
    vis[s] = 2;
    return flag;
}
