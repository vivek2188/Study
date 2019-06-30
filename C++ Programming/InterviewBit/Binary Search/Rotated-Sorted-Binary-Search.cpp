int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(A[mid]==B)
            return mid;
        if(A[mid]<=A[high]){
            if(A[mid]<B and A[high]>=B)
                low = mid+1;
            else
                high = mid-1;
        }
        else if(A[mid]>=A[low]){
            if(A[low]<=B and A[mid]>B)
                high = mid-1;
            else
                low = mid+1;
            
        }
    }
    return -1;
}

