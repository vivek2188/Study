int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size(), m=A[0].size();
    int supposed_row = -1;
    for(int i=0;i<n;i++){
        if(A[i][m-1]>=B){
            supposed_row=i;
            break;
        }
    }
    if(supposed_row==-1)
        return 0;
    int low=0, high=m-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(A[supposed_row][mid]==B)
            return 1;
        if(A[supposed_row][mid]>B)
            high = mid-1;
        else
            low = mid+1;
    }
    return 0;
}

