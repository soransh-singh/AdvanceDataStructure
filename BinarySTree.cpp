#include<iostream>
#include<string.h>
using namespace std;

class Exception{
	char *s;
	public:
	Exception(char *x){
		s = new char[strlen(x)+1];
		strcpy(s, x);
	}
	friend ostream & operator <<(ostream &out, Exception x){
		out << x.s;
		return out;
	}
};

template <class T>
class Queue{
	T *q;
	int rear, front, length;
	public:
	Queue(int n = 0){
		length = n;
		q = new T[length];
		rear = front = -1;
	}
	bool isEmpty(){
		return front == -1 ? true : false;
	}
	T getFront(){
		return q[front];
	}
	T getRear(){
		return q[rear];
	}
	int size(){
		if(front <= rear)
			return rear - front + 1;
		else
			return length - front + rear + 1;
	}

	void insert(T x){
		if((rear + 1) % length == front)
			throw Exception("Queue is full.");
		if(rear == -1)
			front = rear = 0;
		else
			rear = (rear + 1) % length;
		q[rear] = x;
	}

	T del(){
		if(front == -1)
			throw Exception("Queue is empty.");
		T x = q[front];
		if(front == rear)
			front = rear = -1;
		else
			front = (front + 1) % length;
		return x;
	}
	void display();
};
template<class T>
void Queue<T>::display(){
	cout<<"\nContent of queue are: ";
	int f = front;
	while(f != rear){
		cout<< q[f] <<", ";
		f = (f + 1) % length;
	}
	cout << q[f];
}

class Node{
	public:
	int data;
	Node *left, *right;
};

class BinarySearchTree{
	Node *root;
	public:
	BinarySearchTree();
	bool isEmpty();
	int height(Node *r);
	int noOfNodes(Node *r);
	void inOrder(Node *r);
	void postOrder(Node *r);
	void preOrder(Node *r);
	void levelOrder();
	void insert(int x);
	void del(int x);
	void search(char x);
	Node *getRoot(){return root;}
};

void BinarySearchTree::search(char x){
	Node *r = root;
	while(r != NULL && r->data != x)
	{
		if(x < r->data)
			r = r->left;
		else
			r = r->right;
	}
	if(r != NULL)
	{
		cout<<"\n" << x  << " found in the tree node address = " << r <<"left=" <<r->left<<"right="<<r->right<<"data="<<r->data;
	}
	else
		cout << "\nx does not exist in the tree";
}

void BinarySearchTree::inOrder(Node *r){
	if(r->left != NULL)
		inOrder(r->left);
	if(r != NULL)
		cout <<r<<"("<<r->left<<", " << r->data << ", " << r->right << ")   ";
	if(r->right != NULL)
		inOrder(r->right);
}

void BinarySearchTree::preOrder(Node *r){
	if(r != NULL)
		cout <<r<<"("<<r->left<<", " << r->data << ", " << r->right << ")   ";
	if(r->left != NULL)
		preOrder(r->left);
	if(r->right != NULL)
		preOrder(r->right);
}

void BinarySearchTree::postOrder(Node *r){
	if(r->left != NULL)
		postOrder(r->left);
	if(r->right != NULL)
		postOrder(r->right);
	if(r != NULL)
		cout <<r<<"("<<r->left<<", " << r->data << ", " << r->right << ")   ";
}

void BinarySearchTree::levelOrder(){
	if(root == NULL) return;
	Queue <Node *> q(10);
	q.insert(root);
	while(q.isEmpty() == false){
		Node *r = q.del();
		cout<<r<<"("<<r->left<<", " << r->data << ", " << r->right << ")   ";
		if(r->left != NULL)
			q.insert(r->left);
		if(r->right != NULL)
			q.insert(r->right);
	}
}

BinarySearchTree::BinarySearchTree(){
	root = NULL;
}

bool BinarySearchTree::isEmpty(){
	if (root == NULL) return true;
	else return false;
}

int BinarySearchTree::height(Node *r){
	if(r == NULL) return 0;
	if(height(r->left) > height(r->right))
		return 1 + height(r->left);
	else
		return 1 + height(r->right);
}

void BinarySearchTree::insert(int x){
	Node *r = root;
	Node *p=NULL;
	while(r != NULL){
	  if(r->data == x){
		  throw Exception("Data already exist insertion failed");
	  }
	  if(x < r->data){
		  p = r;
		  r = r->left;
	  }
	  else{
		  p = r;
		  r = r->right;
	  }
	}
	Node *nNode = new Node();
	nNode->data = x;
	nNode->left = nNode->right = NULL;
	if(root == NULL)
		root = nNode;
	else if(x < p->data)
		p->left = nNode;
	else
		p->right = nNode;
}

void BinarySearchTree::del(int x){
	if(root == NULL) 
		throw Exception("BST is empty. Deletion failed.");
	Node *r = root, *p = NULL; 
	while(r != NULL && r->data != x){
		if(x < r->data){
			p = r;
			r = r->left;
		}
		else{
			p = r;
			r = r->right;
		}
	}
	if(r == NULL){
		throw Exception("the data does not exist in the BST. Deletion failed.");
	}

	cout << "Information of node is to be deleted " << r << r->data << r->left << r->right;
	if(r == root)
	{
		root = NULL;
		delete(r);
	}
	else {
		//case 1: delete leaf node
		if(r->left == NULL && r->right == NULL){
			if(p->left == r)
				p->left = NULL;
			else
				p->right = NULL;

			delete(r);
		}
		//case 2: delete node having one child
		if((r->left == NULL && r->right != NULL) || (r->left != NULL && r->right == NULL)){
			if(p->left == r)
				if(r->left != NULL)
					p->left = r->left;
				else
					p->left = r->right;
			else
				if(r->left != NULL)
					p->right = r->left;
				else
					p->right = r->right;

			r->left = r->right = NULL;
			delete(r);
		}
		//case 3: delete node heving two children
		if(r->left != NULL && r->right != NULL){
			//Finding the inOrder successor of node x
			Node *inOrderSucc = r->right, *inOrderSuccP = r;
			while(inOrderSucc->left != NULL){
				inOrderSuccP = inOrderSucc;
				inOrderSucc = inOrderSucc->left;
			}
			r->data = inOrderSucc->data;
			//deleting inorder successor
			if(r == inOrderSuccP)
				inOrderSuccP->right = inOrderSucc->right;
			else
				inOrderSuccP->left = inOrderSucc->right;

			inOrderSucc->right = NULL;
			delete(inOrderSucc);
		}
	}
}


int main(){
	BinarySearchTree bt;
	bt.insert(3);
	bt.insert(1);
	bt.insert(2);
	bt.insert(5);
	bt.insert(4);
	bt.insert(6);
	cout << "height="<<bt.height(bt.getRoot());
	cout<<"\nInorder:";
	bt.inOrder(bt.getRoot());
	cout<<"\npre-order:";
	bt.preOrder(bt.getRoot());
	cout<<"\nPost-order:";
	bt.postOrder(bt.getRoot());
	cout<<"\nLevel-order:";
	bt.levelOrder();
	return 0;
}
