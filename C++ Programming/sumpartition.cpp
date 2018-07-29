#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        int mini = INT_MAX;
        int sum = 0;
        for(int i=0;i<n;i++)
            sum += a[i];
        int mat[sum+1] = {0};
        for(int i=0;i<n;i++){
            int temp[sum+1];
            for(int j=0;j<=sum;j++)
                temp[j] = mat[j];
            for(int j=1;j<=sum;j++){
                if(a[i]<=j){
                    int itna = mat[j];
                    int utna = a[i] + mat[j-a[i]];
                    if(utna>itna)
                        temp[j] = utna;
                    mini = min(mini,abs(sum-2*temp[j]));
                }
            }
            for(int j=0;j<=sum;j++)
                mat[j] = temp[j];
        }
        cout << mini << "\n";
    }
}