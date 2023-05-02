#include<bits/stdc++.h>

using namespace std;

class Node;
class DoublyLinkedList;
int max(int a[], int n);

class Node{
    public:

    int data;
    Node* Llink;
    Node* Rlink;

    Node(){
        data = 0;
        Llink = NULL;        
        Rlink = NULL;
    }

    Node(int data){
        this->data = data;
        this->Llink = NULL;        
        this->Rlink = NULL;
    }
};

class DoublyLinkedList{
    public:
    Node * first;

    DoublyLinkedList();
    void create(int n);
    bool isEmpty();
    int size();
    void insert(int x, int index);
    int del(int index);
    int indexOf(int x);
    int get(int index);
    void display();
};

DoublyLinkedList::DoublyLinkedList(){
    first = NULL;
}

void DoublyLinkedList::create(int n){
    Node *cur; 
    for(int i=0; i<n; i++){
        if(i==0){
            first = new Node();
            cur = first;
        }else{
            Node *prev = cur;
            cur->Rlink = new Node();
            cur = cur->Rlink;
            cur->Llink = prev;

        }
        cout<<"Enter data: ";
        cin>>cur->data;        
    }
    cur->Rlink = first;
    first->Llink = cur;
}

bool DoublyLinkedList::isEmpty(){
    return (first== NULL);
}

int DoublyLinkedList::size(){
    if(first==NULL)
        return 0;
    int size = 1;
    Node *cur = first;
    while(cur->Rlink != first){
        size++;
        cur = cur->Rlink;
    }
    return size;
}

void DoublyLinkedList::display(){
    Node *cur = first;
    cout<<"[ ";
    while(cur != NULL){
        cout<<cur->data<<",";
        cur = cur->link;
    }
    cout<<"\b ]\n";
}

void DoublyLinkedList::insert(int x, int index=0){
    // throw invalid_argument("Array is Full");
    if(index<0 or index>size()){
        throw invalid_argument("Invalid Index");
    }
    Node *newNode = new Node();
    newNode->data = x;
    newNode->Llink = newNode;
    newNode->Rlink = newNode;
    if(first == NULL){
        first = newNode
    }else if(index == 0){
        Node * last = first.Llink;
        Node * next=first;
        newNode->Rlink = next;
        newNode->Llink = last;
        first = newNode;
        last->Rlink=first;
        next->Llink=last->Rlink
    }else{
        Node *prev = first;
        for(int i=1; i<index; i++){
            prev = prev->link;
        }
        newNode->link = prev->link;
        prev->link = newNode;
    }
}

int DoublyLinkedList::del(int index){
    if(size() == 0){
        throw invalid_argument("Linked List is empty.");
    }
    if(index<0 or index>size()){
        throw invalid_argument("Invalid Index");
    }
    Node *delNode = new Node();
    int x;
    if(index == 0){
        x = first->data;
        delNode = first;
        first = first->link;
    }else{
        Node *prev= first;
        for(int i=1; i<index; i++){
            prev = prev->link;
        }
        delNode = prev->link;
        x = delNode->data;
        prev->link = delNode->link;
    }
    return x;
}

int DoublyLinkedList::indexOf(int x){
    int index=0;
    Node *cur = first;
    while(cur != NULL and cur->data != x){
        cur = cur->link;
        index++;
    } 
    return (cur==NULL)?-1:index;
}

int DoublyLinkedList::get(int index){
    Node *cur = first;
    for(int i=0; i<=index; i++){
        cur = cur->link;
    }
    return cur->data;
}

