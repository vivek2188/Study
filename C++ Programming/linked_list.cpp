#include <bits/stdc++.h>
using namespace std;

struct Node{
	int key;
	Node* next = NULL;
	Node* prev = NULL;
};

Node* create_newnode(int key){
	Node* x = new Node;
	x->key = key;
	x->prev = x->next = NULL;
	return x;
}

Node* search(Node* head,int val){
	Node* x = head;
	while(x!=NULL and x->key!=val)
		x = x->next;
	return x;
}

Node* insert(Node* head,int key){
	Node* x = create_newnode(key);
	x->next = head;
	if(head!=NULL)
		head->prev = x;
	head = x;
	return head;
}

Node* del(Node* head,int val){
	if(head==NULL)
		cout << "Empty\n";
	else{
		Node* x = search(head,val);
		if(x!=NULL){
			if(x->prev==NULL)
				head = x->next;
			else x->prev->next = x->next;
			if(x->next!=NULL)
				x->next->prev = x->prev;
		}
	}
	return head;
}

void print_list(Node* head){
	Node* st = head;
	if(head==NULL)
		cout << "Empty\n";
	else{
		while(st!=NULL){
			cout << st->key << " ";
			st = st->next;
		}
		cout << endl;
	}
}

int main(){
	Node *head,*tail;
	head = tail = NULL;
	char ch = 't';
	while(ch=='t'){
		int op,val;
		cin >> op;
		if(op==1){
			cout << "Value: ";
			cin >> val;
			Node* sr = search(head,val);
			if(sr==NULL)
				cout << "Not Found\n";
			else cout << "Found\n";
		}
		else if(op==2){
			cout << "Value: ";
			cin >> val;
			head = insert(head,val);
		}
		else if(op==3){
			cout << "Value: ";
			cin >> val;
			head = del(head,val);
		}
		else
			print_list(head);	
		cin >> ch;
	}
	
	return 0;
}