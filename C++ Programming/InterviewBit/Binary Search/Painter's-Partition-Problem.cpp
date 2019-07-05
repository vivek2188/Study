int Solution::paint(int A, int B, vector<int> &C) {
    int modulo = 10000003;
    B = B%modulo;
    int n = C.size();
    long long int low=C[0], high=C[0];
    for(int i=1;i<n;i++){
        if(C[i]>low)
            low = C[i];
        high += (long long int)C[i];
    }
    if(A>=n){
        low = low%modulo;
        return (B*low)%modulo;
    }
    if(A==1){
        high = high%modulo;
        return (B*high)%modulo;
    }
    while(low<high){
        long long int mid = low+(high-low)/2;
        long long int n_workers = 1;
        int i=0;
        long long int carry = 0;
        while(i<n){
            if(carry+(long long int)C[i]<=mid)
                carry += (long long int)C[i];
            else{
                n_workers++;
                carry = (long long int)C[i];
            }
            i++;
        }
        if(n_workers<=A)
            high = mid;
        else
            low = mid+1;
    }
    low = low%modulo;
    return (B*low)%modulo;
}
