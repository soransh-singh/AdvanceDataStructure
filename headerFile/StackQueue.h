#include<iostream>
#include<stdexcept>

using namespace std;

namespace SQueue{
  template<typename obj>
  class StackQueue{
  private:
    obj *arr;
    int front, rear, tos, len, n;
  public:
    StackQueue(int length){
        n=length;
        len=2*n;
        arr = new obj[len];
        front=len;
        rear=len;
        tos=-1;
    }

    /* Queue Functions */ 
    bool isQueueEmpty(){
        return (rear==len);
    }
    void insert(obj x){
        if(rear==len/2){
            throw invalid_argument("Queue is Full");
        }
        if(rear==len){
            front=len-1;
            rear=len-1;
        }else{
            rear--;
        }
        arr[rear] = x;
    }
    obj del(){
        if(front==len){
            throw invalid_argument("Queue Is Empty");
        }
        obj x = arr[front];
        if(front==rear){
            front = len;
            rear=len;
        }else{
            front--;
        }
        return x;
    }

    void displayQueue(){
        for(int i=front; i>=rear; i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    /* Stack Functions */
    bool isStackEmpty(){
        return (tos==-1);
    }
    void push(obj x){
        if(tos == len/2-1){
            throw invalid_argument("Stack Is Full");
        }
        tos++;
        arr[tos]=x;
    }
    obj pop(){
        if(tos == -1){
            throw invalid_argument("Stack is Empty");
        }
        obj x = arr[tos];
        tos--;
        return x;
    }

    void displayStack(){
        for(int i=0; i<=tos; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

  };
}