#include<bits/stdc++.h>
using namespace std;

int checkOp ( string s ){
	int l = s.length();
	int i =0;
	while(i!=l-1 && l>=2){
		if((s[i]=='/'&&s[i+1]=='/')||(s[i]=='/'&&s[i+1]=='*'))
			return true;
		i++;
	}
	return false;
	
}

int main(){
	string line;
	ifstream in("remove_spaces.cpp");
	int ctr = 0;
	while( getline( in, line ) ) {
		if(checkOp(line)){
			ctr++;
		}
	}
     	cout << "No of comment(s) is  : " << ctr << endl;
	return 0;
}
