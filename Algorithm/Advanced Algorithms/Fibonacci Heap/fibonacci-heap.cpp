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
			return nodes + 2 * marked_nodes;
		}
};

int main(){
	FibonacciHeap obj;
	Node *head = obj.minimum();
	if(head==NULL)
		cout << "Empty\n";
	return 0;
}
