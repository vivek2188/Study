#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string s1,s2;
        cin >> s1 >> s2;
        int mat[m+1][n+1];
        for(int i=0;i<=n;i++)
            mat[0][i] = 0;
        for(int i=0;i<=m;i++)
            mat[i][0] = 0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[j-1]==s2[i-1])
                    mat[i][j] = mat[i-1][j-1] + 1;
                else mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
            }
        }
        cout << mat[m][n] << "\n";
    }
}