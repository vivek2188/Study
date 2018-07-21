#include <bits/stdc++.h>
using namespace std;

int* max_cross_sub(int c[],int p,int q,int r){
	int leftsum = INT_MIN;
	int rightsum = INT_MIN;
	int left_indx = q ; 
	int right_indx = q+1;
	int sum = 0;
	for(int i=q;i>=p;i--){
		sum = sum + c[i];
		if(leftsum < sum){
			leftsum = sum;
			left_indx = i;
		}
	}
	sum = 0;
	for(int i=q+1;i<=r;i++){
		sum = sum + c[i];
		if(rightsum < sum){
			rightsum = sum;
			right_indx = i;
		}
	}
	int a[] = {left_indx,right_indx,leftsum+rightsum};
	return a;
}

int* max_sub(int c[],int p,int r){
	if(p==r){
		int a[]  = {p,r,c[r]};
		return a;
	}
	int q = (p+r)/2;
	int* lf = max_sub(c,p,q);
	int* rt = max_sub(c,q+1,r);
	int* mid = max_cross_sub(c,p,q,r);
	if(lf[2] >= rt[2] and lf[2] >= mid[2])
		return lf;
	else if(rt[2] >= lf[2] and rt[2] >= mid[2])
		return rt;
	else return mid;
}
int main(){
	int days;
	cout << "Days: ";
	cin >> days;
	int stock_prices[days];
	for(int i=0;i<days;i++)
		cin >> stock_prices[i];
		
	int difference[days];
	difference[0] = 0;
	for(int i=1;i<days;i++)
		difference[i] = stock_prices[i] - stock_prices[i-1];
		
	int *ans = max_sub(difference,1,days-1);
	if( ans[2] < 0 )
		cout << "Bought and sold on same day with neither profit nor loss.";
	else cout << "Bought on day: " << ans[0]-1 << ". Sold on day: " << ans[1]+1 << ". Profit: " << ans[2] ;
	return 0;
}
