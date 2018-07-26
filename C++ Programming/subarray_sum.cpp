#include <bits/stdc++.h>
using namespace std;

struct node{
    int s,e;
};

node* subarraywithsum(int a[],int sum,int n){
    int i,j;
    i = j = 1;
    node* newnode = NULL;
    while(i<=n and j<=n){
        if(a[j]-a[i-1] == sum){
            newnode = new node;
            newnode->s = i;
            newnode->e = j;
            break;
        }
        else if(a[j]-a[i-1]<sum)
            j++;
        else if(a[j]-a[i-1]>sum)
            i++;
    }
    return newnode;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n ,sub_sum;
        cin >> n >> sub_sum; 
        int a[n+1];
        a[0] = 0;
        for(int i=1;i<=n;i++)   
            cin >> a[i];
        int sum[n+1] = {0};
        for(int i=1;i<=n;i++)   
            sum[i] += sum[i-1] + a[i];
        node* newnode = subarraywithsum(sum,sub_sum,n);
        if(newnode==NULL)
            cout << -1 << "\n";
        else cout << newnode->s << " " << newnode->e << "\n";
    }
}