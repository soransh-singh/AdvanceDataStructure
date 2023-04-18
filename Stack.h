#include<iostream>
#include<stdexcept>

using namespace std;

namespace Stack{
    /* Class Stack */ 

    template<typename obj>
    class StackArr{
    private:
        obj *arr;
        int tos;
        int length;
    public:

        StackArr(int l){
            length = l;
            arr = new obj[length];
            tos = -1;
        }

        bool isEmpty(){
            return (tos == -1);
        }

        int size(){
            return tos+1;
        }

        // obj top();
        obj pop(){
            if(tos == -1){
                throw invalid_argument("Stack is Empty");
            }
            obj x = arr[tos];
            tos--;
            return x;
        }

        void push(obj x){
            if(tos == length-1){
                throw invalid_argument("Stack is Full");
            }
            tos++;
            arr[tos] = x;

        }

        obj peep(int index){
            if(index<0 or index>tos){
                throw invalid_argument("Invalid Index");
            }
            return arr[tos - index];
        }

        void display(){
            for(int i=0; i<=tos; i++){
                cout<<arr[i]<<" ";
            }
        }
    };

    



}