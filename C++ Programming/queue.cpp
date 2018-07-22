#include <bits/stdc++.h>
using namespace std;

void queue_empty(int head,int tail){
	if(head==tail)
		cout << "YES\n";
	else cout << "NO\n"; 	
}

int enqueue(int a[],int size,int head,int tail,int val){
	if((tail==size-1 and head==0) or (head==tail+1)){
		cout << "Queue Overflow\n";
	}
	else{
		a[tail] = val;
		if(tail==size-1)
			tail = 0;
		else tail = tail + 1;
		cout << "Queue after Insertion: ";
		for(int i=0;i<size;i++)
			cout << a[i] << " ";
		cout << "\n";
	}
	return tail;
}

int dequeue(int a[],int size,int head,int tail){
	if(head==tail)
		cout << "Queue Underflow\n";
	else{
		cout << "Deleted: " << a[head] << "\n";
		a[head] = 0 ;
		cout << head<< "\n";
		if(head==size-1)
			head = 0;
		else head = head + 1;
	}
	return head;
}

int main(){
	int size;
	cout << "Size: ";
	cin >> size;
	int a[size] = {0};
	int head, tail ; 
	head = tail = 0;
	char ch = 't';
	while(ch=='t'){
		int op;
		cin >> op;
		if(op==1){
			cout << "Is queue empty " ;
			queue_empty(head,tail);
		}
		else if(op==2){
			int val;
			cout << "Value: ";
			cin >> val;
			tail = enqueue(a,size,head,tail,val);
			cout << head << "  " << tail << "\n";
		}
		else if(op==3){
			head = dequeue(a,size,head,tail);
			cout << head << "  " << tail << "\n";
		}
		else{
			cout << "Array: ";
			for(int i=0;i<size;i++)
				cout << a[i] << " ";
			cout << endl;
		}
		cin >> ch;
	}
	return 0;
}