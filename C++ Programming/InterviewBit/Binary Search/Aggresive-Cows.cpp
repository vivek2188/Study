#include <algorithm>

int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int n = A.size();
    long long int low=A[n-1], high=A[n-1]-A[0];
    for(int i=1;i<n;i++){
        if(A[i]-A[i-1]<low)
            low = A[i]-A[i-1];
    }
    if(B==2)
        return high;
    if(B==n)
        return low;
    while(low<high){
        long long int mid = low+(high-low+1)/2;
        long long int n_cows = 1;
        int i=1;
        int last = 0;
        long long int carry = 0;
        while(i<n){
            if((A[i]-A[last])>=mid){
                n_cows++;
                last = i;
            }
            i++;
        }
        if(n_cows<B)
            high = mid-1;
        else
            low = mid;
    }
    return low;
}

