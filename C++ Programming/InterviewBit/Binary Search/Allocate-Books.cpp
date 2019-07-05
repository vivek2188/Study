int Solution::books(vector<int> &A, int B) {
    //sort(A.begin(), A.end());
    int n = A.size();
    if(B<=0 || B>n)
        return -1;
    
    long long int low, high;
    low = high = A[n-1];
    for(int i=0;i<n-1;i++){
        if(A[i]>low)
            low = A[i];
        high += (long long int)A[i];
    }
    if(B==n)
        return low;
    if(B==1)
        return high;
    while(low<high){
        long long int mid = low+(high-low)/2;
        int n_students = 1;
        long long int carry = 0;
        for(int i=0;i<n;i++){
            if(carry+(long long int)A[i]<=mid)
                carry += (long long int)A[i];
            else{
                carry = (long long int)A[i];
                n_students++;
            }
        }
        if(n_students<=B)
            high = mid;
        else
            low = mid+1;
    }
    return low;
}

