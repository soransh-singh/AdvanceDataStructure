#include<iostream>
#include<stdexcept>

using namespace std;

namespace Queue{
  template<typename obj>
  class queueArr{
  protected:
    obj *q;
    int rear, front, len;
  public:
    queueArr(){

    }
    queueArr(int length){
      len = length;
      q = new obj[len];
      rear=-1;
      front=-1;
    }

    bool isEmpty(){
      return (rear==-1);
    }

    int size(){
      if(rear==-1){
        return 0;
      }else{
        return (rear-front+1);
      }
    }

    void insert(obj x){
      if(rear == len-1){
          throw invalid_argument("Queue is Full");
      }
      if(rear==-1){
        front=0;
        rear=0;
      }else{
        rear++;
      }
      q[rear] = x;
    }

    obj del(){
      if(front==-1){
        throw invalid_argument("Queue is Empty");
      }
      obj x = q[front];
      if(front==rear){
        front=-1;
        rear=-1;
      }else{
        front++;
      }
      return x;
    }

    void display(){
      for(int i=front; i<=rear; i++){
        cout<<q[i]<<" ";
      }
    }
  };


  template<typename obj>
  class circularQueueArr:public queueArr<obj>{
  protected:
    obj *q;
    int rear, front, len;
  public:
    circularQueueArr(int length){
      len = length;
      q = new obj[len];
      rear=-1;
      front=-1;
    }

    int size(){
      if(rear == -1){
        return 0;
      }else if(rear>front){
        return (rear-front+1);
      }else {
        return (len - front + rear + 1);
      }
    }

    void insert(obj x){
      if((rear+1)%len == front){
        throw invalid_argument("Queue is Full");
      }
      if(rear==-1){
        front=0;
        rear=0;
      }else{
        rear=(rear+1)%len;
      }
      q[rear]=x;
    }

    obj del(){
      if(front==-1){
        throw invalid_argument("Queue is Empty");
      }
      obj x = q[front];
      if(front==rear){
        front=-1;
        rear=-1;
      }else{
        front=(front+1)%len;
      }
      return x;
    }

    void display(){
      int i=front;
      do{
        cout<<q[i]<<" ";
        i=(i+1)%len;
      }while(i != rear);
      cout<<q[i]<<" "<<endl;
    }

  };

}
