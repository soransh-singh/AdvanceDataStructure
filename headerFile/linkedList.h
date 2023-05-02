#include<iostream>

using namespace std;


namespace link{
	class Node{   
	public:
		int data;
		Node *link;
		
	};

	class LinkedList
	{
		Node  *first;
	public:
		LinkedList();
		bool isEmpty();
		void insert(int x, int index);
		int del(int index);
		int getSize();
	};

	LinkedList::LinkedList(){
		first = NULL;
	}

	bool LinkedList::isEmpty(){
		return (first == NULL);
	}

	void LinkedList::insert(int x, int index){
		if(index<0 || index>getSize()){
			cout << "Invalid index. Insertion failed.";
			exit(0);
		}
		Node *newNode = new Node();
		newNode->data = x; newNode->link = NULL;
		if(index == 0){
			newNode->link = first; first = newNode;
		}
		else{
			Node *prev = first;
			for(int i=1; i<=index-1; i++)
				prev = prev->link;
			newNode->link = prev->link; prev->link = newNode;
		}
	}

	int LinkedList::del(int index){
		if(first == NULL){
			cout<<"List is empty. Deletion failed.";
			exit(0);
		}
		if(index<0 || index>=getSize()){
			cout<<"Invalid index. Deletion failed.";
			exit(0);
		}
		int x; Node *dl;
		if(index == 0){
			dl = first; x = dl->data; first = dl->link;
		}else{
			Node *prev = first;
			for(int i=1; i<=index-1; i++)
				prev = prev->link;
			dl = prev->link;
			x = dl->data;
			prev->link = dl->link;
		}
		dl->link = NULL;
		delete(dl);
		return x;
	}

	int LinkedList::getSize(){
		int n = 0; Node *cur = first;
		while(cur != NULL){
			n++;
			cur = cur->link;
		}
		return n;
	}
	
}

/*

	/---------------/
	BucketSort Implementation 
	/---------------/ 
	int max(int a[], int n){
		int mx = a[0];
		for(int i=1; i<n; i++)
			if(a[i]>mx) mx = a[i];
		return mx;
	}

	void bucketSort(int a[], int n){
		int mx = max(a, n);
		LinkedList L[mx+1];
		for(int i=0; i<n; i++){
			L[a[i]].insert(a[i], 0);
		}
		int i=0;
		for(int j=0; j<=mx; j++){
			while(L[j].isEmpty()==false)
				a[i++] = L[j].del(L[j].getSize()-1);
		}
	}

	void read(int a[], int n){
		cout << "Enter " << n << " positive integers ";
		for(int i=0; i<n; i++)
			cin >> a[i];
	}
	void print(int a[], int n){
		cout<<"\nThe list is [";
		for(int i=0; i<n; i++)
			cout<<a[i]<<", ";
		cout<<"\b\b]";
	}
*/ 
