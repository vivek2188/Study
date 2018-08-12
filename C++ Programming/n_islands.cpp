#include <bits/stdc++.h>
using namespace std;
#define MAX 1000  
int findIslands(int A[MAX][MAX],int N,int M);
int main() {
	int T;
	cin>>T;
	int A[MAX][MAX];
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		memset(A,0,sizeof A);
		for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		cin>>A[i][j];
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}

void dfs(int a[MAX][MAX],int i,int j,int n,int m,int vis[MAX][MAX]){
    vis[i][j] = 1;
    if(!vis[i+1][j] and i<n-1 and a[i+1][j]==1)
        dfs(a,i+1,j,n,m,vis);
    if(!vis[i+1][j+1] and i<n-1 and j<m-1 and a[i+1][j+1]==1)
        dfs(a,i+1,j+1,n,m,vis);
    if(!vis[i+1][j-1] and i<n-1 and j>0 and a[i+1][j-1]==1)
        dfs(a,i+1,j-1,n,m,vis);
    if(!vis[i][j+1] and j<m-1 and a[i][j+1]==1)
        dfs(a,i,j+1,n,m,vis);
    if(!vis[i][j-1] and j>0 and a[i][j-1]==1)
        dfs(a,i,j-1,n,m,vis);
    if(!vis[i-1][j] and i>0 and a[i-1][j]==1)
        dfs(a,i-1,j,n,m,vis);
    if(!vis[i-1][j+1] and i>0 and j<m-1 and a[i-1][j+1]==1)
        dfs(a,i-1,j+1,n,m,vis);
    if(!vis[i-1][j-1] and i>0 and j>0 and a[i-1][j-1]==1)
        dfs(a,i-1,j-1,n,m,vis);
}

int findIslands(int a[MAX][MAX], int N, int M){
    int vis[MAX][MAX];
    memset(vis,0,sizeof(vis));
    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(a[i][j]==1 and vis[i][j]==0){
                dfs(a,i,j,N,M,vis);
                //cout << i << " " << j << "\n";
                cnt++;
            }
        }
    }
    return cnt;
}
