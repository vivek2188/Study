#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n==0)
            cout << "YES\n";
        else{
            int a[n+1];
            a[0] = 0;
            for(int i=1;i<=n;i++)
                cin >> a[i];
            sort(a,a+n+1);
            int sum = 0;
            for(int i=1;i<=n;i++)
                sum += a[i];
            if(sum%2)
                cout << "NO\n";
            else{
                sum /= 2;
                int num = 0;
                for(int i=1;i<=n;i++){
                    if(a[i]>sum)
                        break;
                    num++;
                }
                int mat[sum+1] = {0};
                bool flag = 0;
                for(int i=1;i<=num;i++){
                    int temp[sum+1];
                    for(int j=0;j<=sum;j++)
                        temp[j] = mat[j];
                    for(int j=1;j<=sum;j++){
                        if(a[i]<=j){
                            if(a[i]+mat[j-a[i]]>mat[j])
                                temp[j] = a[i] + mat[j-a[i]];
                        }
                    }
                    if(temp[sum]==sum){
                        flag = 1;
                        break;
                    }
                    for(int j=0;j<=sum;j++)
                        mat[j] = temp[j];
                }
                if(flag)
                    cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}