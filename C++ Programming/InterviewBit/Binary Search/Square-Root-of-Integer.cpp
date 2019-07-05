int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==0)
        return 0;
    if(A==1)
        return 1;
    long long int low=1, high=A/2+1;
    while(low<high){
        long long int mid = low+(high-low+1)/2;
        if(mid*mid==A)
            return mid;
        if(mid*mid>A)
            high = mid-1;
        else if(mid*mid<A)
            low = mid;
    }
    return low;
}

