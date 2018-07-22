#include <bits/stdc++.h>
using namespace std;

int stack_empty(int tos){
	if(tos==-1)
		cout << "YES";
	else cout << "NO";
}

int push(int a[],int tos,int val,int size){
	if(tos==size-1)
		cout << "Stack Overflow" << "\n";
	else{
		tos = tos + 1;
		a[tos] = val;
		cout << "Array after Insertion: ";
		for(int i=0;i<size;i++)
			cout << a[i] << " ";
		cout << "\n";
		cout << "TOS: " << tos << "\n"; 
	}
	return tos;
}

int pop(int a[],int tos,int size){
	if(tos==-1)
		cout << "Stack Underflow" << "\n";
	else{
		cout << "Deleted: " << a[tos];
		a[tos] = 0;
		tos = tos - 1;
	}
	return tos;
}

int main(){
	int size;
	cout << "Size: " ;
	cin >> size;
	int tos = -1;
	int a[size] = {0};
	char ch = 't';
	while(ch=='t'){
		int op;
		cin >> op;
		if(op==1){
			cout << "Is stack empty " ;
			stack_empty(tos);
			cout << "\n";
		}
		else if(op==2){
			int val;
			cout << "Value: ";
			cin >> val;
			tos = push(a,tos,val,size);
		}
		else if(op==3){
			tos = pop(a,tos,size);
		}
		else{
			cout << "Stack: ";
			for(int i=0;i<size;i++)
				cout << a[i] << " ";
			cout << "\n";	
		}
		cin >> ch;
	}	
	return 0;
}