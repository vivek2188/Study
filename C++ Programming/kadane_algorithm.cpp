#include <bits/stdc++.h>
using namespace std;

int max_cross_sum(int a[],int p,int q,int r){
    int sum,left_sum,right_sum;
    sum = 0;
    left_sum = right_sum = INT_MIN;
    for(int i=q;i>=p;i--){
        sum += a[i];
        if(sum>left_sum)
            left_sum = sum;
    }
    sum = 0;
    for(int i=q+1;i<=r;i++){
        sum += a[i];
        if(sum>right_sum)
            right_sum = sum;
    }
    return left_sum+right_sum;
}

int max_subarray_sum(int a[],int p,int r){
    if(p<=r){
        if(p==r)
            return a[p];
        int q = (p+r)/2;
        int left_sum = max_subarray_sum(a,p,q);
        int right_sum = max_subarray_sum(a,q+1,r);
        int mid_sum = max_cross_sum(a,p,q,r);
        if(left_sum>right_sum and left_sum>mid_sum)
            return left_sum;
        else if(right_sum>left_sum and right_sum>mid_sum)
            return right_sum;
        else return mid_sum;
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        cout << max_subarray_sum(a,0,n-1) << "\n";
    }
}