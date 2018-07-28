int maxLen(int a[], int n){
    for(int i=0;i<n;i++)
        if(a[i]==0)
            a[i]=-1;
    int sum,mx;
    sum = mx = 0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        sum += a[i];
        if(sum==0)
            mx = i+1;
        if(mp.find(sum)!=mp.end())
            mx = max(mx,i-mp[sum]);
        else mp[sum] = i;
    }
    return mx;
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
        cout << maxlen(a,n) << "\n";
    }
    return 0;
}