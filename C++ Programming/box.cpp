#include <bits/stdc++.h>
using namespace std;

bool comp(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2){
    if(p1.first.first*p1.first.second<p2.first.first*p2.first.second)
        return true;
    return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pair<pair<int,int>,int> >box;
		for(int i=0;i<n;i++){
			int a,b,c;
			cin >> a >> b >> c;
	        box.push_back(make_pair(make_pair(a,b),c));
	        box.push_back(make_pair(make_pair(b,c),a));
	        box.push_back(make_pair(make_pair(c,a),b));
		}
		sort(box.begin(),box.end(),comp);
		vector<int>height;
		for(int i=0;i<box.size();i++){
			if(box[i].first.first>box[i].first.second)
				swap(box[i].first.first,box[i].first.second);
			height.push_back(box[i].second);
		}
		for(int i=box.size()-2;i>=0;i--){
			for(int j=box.size()-1;j>i;j--){
				if(box[i].first.first<box[j].first.first and box[i].first.second<box[j].first.second and box[i].second<box[j].second+height[i])
					box[i].second = box[j].second+height[i];
			}
		}
		cout << box[0].second << "\n";
	}
}