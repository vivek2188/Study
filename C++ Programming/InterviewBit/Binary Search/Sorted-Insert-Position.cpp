int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    if(B<A[0])
        return 0;
    if(B>A[n-1])
        return n;
        
    int low=0, high=n-1;
    while(low<high){
        int mid = low+(high-low+1)/2;
        if(A[mid]==B)
            return mid;
        if(A[mid]>B)
            high = mid-1;
        else if(A[mid]<B)
            low = mid;
    }
    if(A[low]==B)
        return low;
    return low+1;
}

