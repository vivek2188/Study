int Smaller(vector<vector<int> > &A, int B){
    int n=A.size(), m=A[0].size();
    int count = 0;
    for(int i=0;i<n;i++){
        if(A[i][m-1]<B){
            count += m;
            continue;
        }
        if(A[i][0]>=B)
            continue;
        int low = 0, high = m-1;
        while(low<high){
            int mid = low+(high-low+1)/2;
            if(A[i][mid]>=B)
                high = mid-1;
            else if(A[i][mid]<B)
                low = mid;
        }
        count += low+1;
    }
    return count;
}

int Greater(vector<vector<int> > &A, int B){
    int n=A.size(), m=A[0].size();
    int count = 0;
    for(int i=0;i<n;i++){
        if(A[i][0]>B){
            count += m;
            continue;
        }
        if(A[i][m-1]<=B)
            continue;
        int low=0, high=m-1;
        while(low<high){
            int mid = low+(high-low+1)/2;
            if(A[i][mid]>B)
                high = mid-1;
            else if(A[i][mid]<=B)
                low = mid;
        }
        count += m - low - 1;
    }
    return count;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int n=A.size(), m=A[0].size();
    int low=A[0][0], high=A[0][m-1];
    for(int i=1;i<n;i++){
        if(A[i][0]<low)
            low = A[i][0];
        if(A[i][m-1]>high)
            high = A[i][m-1];    
    }
    int allowed = (n*m-1)/2;
    while(low<=high){
        int mid = low+(high-low)/2;
        int lt_x = Smaller(A, mid);
        int gt_x = Greater(A, mid);
        if(lt_x<=allowed and gt_x<=allowed)
            return mid;
        if(lt_x>allowed)
            high = mid-1;
        else if(gt_x>allowed)
            low = mid+1;
    }
    return -1;
}

