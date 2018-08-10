// O(n) Time Complexity
/*
#include <bits/stdc++.h>
using namespace std;

int getbits(int n){
    int cnt = 0;
    while(n>0){
        cnt ++;
        n = n - (n&-n);
    }
    return cnt;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        int count = 0;
        for(int i=1;i<=n;i++){
            count += getbits(i);
        }
        cout << count << "\n";
    }
}
*/

// Much faster algorithm with O(logN) time Complexity
#include <bits/stdc++.h>
using namespace std;

int getbits(int n){
    int cnt = 0;
    while(n>0){
        cnt ++;
        n = n - (n&-n);
    }
    return cnt;
}

int count_bits(int n){
    if(n<=0)
        return 0;
    if((n&(n+1))==0){
        return log2(n+1) * (n+1)/2;
    }
    int m = pow(2,int(log2(n))) - 1;
    return count_bits(m) + count_bits(n-m-1) + n-m; 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        cout << count_bits(n) << "\n";
    }
}