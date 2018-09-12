#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Node Structure
struct Node{
	bool mark;	      // Whether the node has lost a child since 
		     	      // it was made child of another node.
	int key;      	      // Value of the node
	int degree;           // Degree of the node
	Node *parent;         // Parent Pointer
	Node *left, *right;   // Siblings
	Node *child;	      // Child Pointer
};

Node* createnode(int key){
	Node *newnode = new Node;
	newnode->key = key;
	newnode->parent = newnode->child = NULL;
	newnode->left = newnode->right = newnode;
	newnode->degree = 0;
	newnode->mark = false;
	return newnode;
}

/*
 The maximum degree of any node in an n-node binomial tree is lg n. A
 Fibonacci heap which supports only the mergeable heap operations 
 is a collection of unordered binomial trees. The largest tree that 
 can exist in such a collection contains n nodes. The largest possible 
 degree is therefore log n.
*/

class FibonacciHeap{
	Node *head;
	int nodes, marked_nodes, num_trees;
	public:
		// Initializer
		FibonacciHeap(){
			head = NULL;
			nodes = marked_nodes = num_trees = 0;
		}
		void fib_heap_initializer(){
			head = NULL;
			nodes = marked_nodes = num_trees = 0;
		}
		// Pointer to the minimum node
		Node* minimum(){
			return head;
		}
		// Potential Calculator
		void potential_function(){
			cout << num_trees + 2 * marked_nodes << "\n";
		}
		// Insertion
		void fib_heap_insert(int key){
			Node *x = createnode(key);
			if(head==NULL)
				head = x;
			else{
				// Insert new node to root list
				Node *l1 = head->left;
				Node *l2 = x->left;
				l1->right = x;
				x->left = l1;
				l2->right = head;
				head->left = l2;
				// Head Updation
				if(head->key > x->key)
					head = x;
			}
			nodes += 1;
		}
		// Print root list
		void print_root_list(){
			if(head==NULL){
				cout << "Empty fibonacci heap\n";
				return;
			}
			Node *h = head;
			cout << "Root list: ";
			do{
				cout << h->key << " ";
				h = h->right;
			}while(h!=head);
			cout << "\n";
		}
		// Union of two fibonacci heaps
		void fib_heap_union(FibonacciHeap H1,FibonacciHeap H2){
			Node *h1 = H1.head, *h2 = H2.head;
			if(h1==NULL || h2==NULL){
				(h1==NULL)?(head=h2):(head=h1);
			}
			else{
				Node *l1 = h1->left;
				Node *l2 = h2->left;
				l1->right = h2;
				h2->left = l1;
				l2->right = h1;
				h1->left = l2;
				// Head Updation
				if(h1->key > h2->key)
					head = h2;
				else head = h1;
			}
			nodes = H1.nodes + H2.nodes;
			return;
		}
		// Extract Min
		Node* fib_heap_extract_min(){
			if(head==NULL){
				cout << "Error: Empty fibonacci heap\n";
				return NULL;
			}
			Node *z = head;
			if(z!=NULL){
				// Adding its children to root list
				Node *ch = z->child;
				Node *ch_copy = ch;
				do{
					if(ch==NULL)
						break;
					Node *l1 = head->left;
					l1->right = ch;
					ch->left = l1;
					Node *chc = ch->right;
					ch->right = head;
					head->left = ch;
					ch = chc;
				}while(ch!=ch_copy);
				// Remove z from the root list
				Node *l = z->left, *r = z->right;
				l->right = r;
				r->left = l;
				if(z==z->right)
					head = NULL;
				else{
					head = z->right;
					consolidate();
				}
				nodes--;
			}
			if(z!=NULL){
				z->child = NULL;
				z->left = z->right = z;
			}
			return z;
		}
		// Consolidation of root list
		void consolidate(){
			int max_deg = floor(log2(nodes));
			Node* A[max_deg+1];
			for(int i=0;i<=max_deg;i++)
				A[i] = NULL;
			Node *w = head;
			unordered_map<Node*,bool>mp;
			do{
				Node *x = w;
				Node *r = w->right;
				mp[w] = 1;
				int d = x->degree;
				while(A[d]!=NULL and d<=max_deg){
					Node *y = A[d];
					if(x->key>y->key)
						swap(x,y);
					fib_heap_link(y,x);
					A[d] = NULL; 
					d = d+1;
				}
				A[d] = x;
				A[d]->left = A[d]->right = A[d];
				w = r;
			}while(mp.find(w)==mp.end());
			head = NULL;
			num_trees = 0;
			for(int i=0;i<=max_deg;i++){
				if(A[i]!=NULL){
					num_trees++;
					if(head==NULL)
						head = A[i];
					else{
						Node *l1 = head->left;
						Node *l2 = A[i]->left;
						l1->right = A[i];
						A[i]->left = l1;
						l2->right = head;
						head->left = l2;
						// Head Updation
						if(head->key > A[i]->key)
							head = A[i];
					}
				}			
			}
		}
		// Linking 
		void fib_heap_link(Node *y,Node *x){
			Node *l = y->left, *r = y->right;
			l->right = r;
			r->left = l;
			x->degree++;
			if(x->child==NULL){
				x->child = y;
				y->left = y->right = y;
			}
			else{
				Node *r = x->child->right;
				x->child->right = y;
				y->left = x->child;
				y->right = r;
				r->left = y;
			}
			y->parent = x;
			if(y->mark==true){
				y->mark = false;
				marked_nodes--;
			}
		}
};

int main(){
	FibonacciHeap H,H1,H2,H3;
	char c = 'y';
	int i;
	while(c=='y' || c=='Y'){
	cout << "1 For INSERT\n2 For MINIMUM\n3 For EXTRACT-MIN\n4 For Union\n5 For Print Root List\n";
	cin >> i;
	Node *head, *deleted;
	switch(i){
		case 1:
			int key;
			cout << "Enter the value: ";
			cin >> key;
			H.fib_heap_insert(key);
			break;
		case 2:
			head = H.minimum();
			if(head!=NULL)
				cout << "Value of head: " << head->key << "\n";
			else cout << "Empty Fibonacci Heap\n";
			break;
		
		case 3:
			deleted = H.fib_heap_extract_min();
			if(deleted!=NULL)
				cout << "Extracted the minimum value: " << deleted->key << "\n";
			break;
		case 4:
			H1.fib_heap_initializer();
			H2.fib_heap_initializer();
			H3.fib_heap_initializer();
			cout << "Number of elements in heap 1: ";
			int m,n;
			cin >> m;
			cout << "Enter the elements: ";
			while(m--){
				int k;
				cin >> k;
				H1.fib_heap_insert(k);
			}
			cout << "Root of the heap 1: " << H1.minimum()->key << "\n";
			cout << "Number of elements in heap 2: ";
			cin >> n;
			cout << "Enter the elements: ";
			while(n--){
				int k;
				cin >> k;
				H2.fib_heap_insert(k);
			}
			cout << "Root of the heap 2: " << H2.minimum()->key << "\n";
			cout << "Performing Union of the above 2 heaps.\n";
			H3.fib_heap_union(H1,H2);
			cout << "Root of the merged heap: " << H3.minimum()->key << "\n"; 
			break;
		case 5:
			H.print_root_list();
			break;
		default:
			cout << "Enter a valid number\n";
	}
	cout << "Want to continue?(Y/N) ";
	cin >> c;
	}
	return 0;
}
