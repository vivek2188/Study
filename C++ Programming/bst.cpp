#include <bits/stdc++.h>
using namespace std;

struct Node{
	int key;
	Node *left, *right, *p;
};

Node* create_newnode(int key){
	Node* node = new Node;
	node->key = key;
	node->left = node->right = node->p = NULL;
	return node;
}

Node* tree_search(Node* root,int key){
	if(root==NULL or root->key == key)
		return root;
	if( key < root->key)
		return tree_search(root->left,key);
	else return tree_search(root->right,key);
}

Node* iterative_tree_search(Node* root,int key){
	Node* st = root;
	while(st!=NULL or st->key!=key){
		if(key<st->key)
			st = st->left;
		else st = st->right;
	}
	return st;
}

Node* tree_minimum(Node* root){
	Node* st = root;
	while(st->left!=NULL)
		st = st->left;
}

Node* tree_maximum(Node* root){
	Node* st = root;
	while(st->right!=NULL)
		st = st->right;
	return st;
}

Node* successor(Node* x){
	if(x->right!=NULL)	
		return tree_minimum(x->right);
	Node* y = x->p;
	while(y!=NULL and x==y->right){
		x = y;
		y = y->p;
	}
	return y;
}

Node* predecessor(Node* x){
	if(x->left!=NULL)
		return tree_maximum(x->left);
	Node* y = x->p;
	while(y!=NULL and x==y->left){
		x = y;
		y = y->p;
	}
	return y;
}

Node* insert(Node* root,int key){
	Node* node = create_newnode(key);
	Node* y = NULL;
	Node* st = root;
	while(st!=NULL){
		y = st;
		if(key<=st->key)
			st = st->left;
		else st = st->right;
	}
	node->p = y;
	if(y==NULL)	
		root = node;
	else if(key<=y->key)
		y->left = node;
	else y->right = node;
	return root;
}

void transplant(Node* root,Node* u,Node* v){
	if(u->p==NULL)
	 	root = v;
	else if(u->p->left==u)
		u->p->left = v;
	else if(u->p->right==u)
		u->p->right = v;
	if(v!=NULL)
		v->p = u->p;
}

Node* del(Node* root,Node* z){
	Node* st = root;
	if(z->left==NULL)
		transplant(root,z,z->right);
	else if(z->right==NULL)
		transplant(root,z,z->left);
	else{
		Node* y = tree_maximum(z->right);
		if(y->p==z){
			transplant(root,y,y->right);
			y->right = z->right;
			y->right->p = y;
		} 
		transplant(root,z,y);
		y->left = z->left;
		y->left->p = y;
	}
		
	return root;
}

void inorder_tree_walk(Node* root){
	if(root!=NULL){
		inorder_tree_walk(root->left);
		cout << root->key << " ";
		inorder_tree_walk(root->right);
	}
}