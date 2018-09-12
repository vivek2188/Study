#include <iostream>
#include <cmath>
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
	int nodes, marked_nodes;
	public:
		// Initializer
		FibonacciHeap(){
			head = NULL;
			nodes = marked_nodes = 0;
		}
		// Pointer to the minimum node
		Node* minimum(){
			return head;
		}
		// Potential Calculator
		void potential_function(){
			cout << nodes + 2 * marked_nodes << "\n";
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
};

int main(){
	FibonacciHeap obj;
	Node *head = obj.minimum();
	if(head==NULL)
		cout << "Empty\n";
	obj.fib_heap_insert(5);
	obj.fib_heap_insert(2);
	obj.fib_heap_insert(3);
	obj.fib_heap_insert(1);
	obj.fib_heap_insert(4);
	obj.fib_heap_insert(6);
	head = obj.minimum();
	cout << head->key << "\n";
	obj.print_root_list();
	return 0;
}
