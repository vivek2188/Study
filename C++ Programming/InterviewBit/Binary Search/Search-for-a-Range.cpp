int upper_bound(const vector<int> &A, int B){
    int n = A.size();
    int low=0, high=n-1;
    while(low<high){
        int mid = low + (high-low+1)/2;
        if(A[mid]==B)
            low = mid;
        else if(A[mid]<B)
            low = mid+1;
        else
            high = mid-1;
    }
    if(low==high and A[low]==B)
        return low;
    return -1;
}

int lower_bound(const vector<int> &A, int B){
    int n = A.size();
    int low=0, high=n-1;
    while(low<high){
        int mid = low + (high-low)/2;
        if(A[mid]==B)
            high = mid;
        else if(A[mid]<B)
            low = mid+1;
        else
            high = mid-1;
    }
    if(low==high and A[low]==B)
        return low;
    return -1;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    ans.push_back(lower_bound(A, B));
    ans.push_back(upper_bound(A, B));
    return ans;
}

