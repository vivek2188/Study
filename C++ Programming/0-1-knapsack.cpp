#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int w;
        cin >> w;
        int val[n+1],weight[n+1];
        for(int i=1;i<=n;i++)
            cin >> val[i];
        for(int i=1;i<=n;i++)   
            cin >> weight[i];
        int mat[n+1][w+1];
        for(int i=0;i<=w;i++)
            mat[0][i] = 0;
        for(int i=1;i<=n;i++)
            mat[i][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                if(weight[i]<=j){
                    if(val[i]+mat[i-1][j-weight[i]]>mat[i-1][j])
                        mat[i][j] = val[i] + mat[i-1][j-weight[i]];
                    else mat[i][j] = mat[i-1][j];
                }
                else mat[i][j] = mat[i-1][j];
            }
        }
        cout << mat[n][w] << "\n";
    }
    return 0;
}