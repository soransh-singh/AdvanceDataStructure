#include<iostream>
#include<stdexcept>

using namespace std;

namespace Arr{
    /* Class: Array */

    template<typename T>
    class Array{
        T *arr;
        int size, length;
        public:
        Array(int n){
            arr = new T[n];
            length = n;
            size=0;
        }

        void insert(T x, int index){
            if(size == length){
                throw invalid_argument("Array is Full");
            }
            if(index > size){
                throw invalid_argument("Invalid Index");
            }
            // int iter = 0;
            for(int i=size; i>index; i--){
                arr[i]= arr[i-1];
                // iter++;
            }
            // cout<<"Number of movement to input "<<x<<" is "<<iter<<endl;
            arr[index]= x;
            size++;
        }

        T del(int index){
            
            if(size==0){
                throw invalid_argument("Array is Empty");
            }

            if(index>= size){
                throw invalid_argument("Invalid Index");
            }
            
            // int iter = 0;
            int val = arr[index];
            for(int i=index; i<size; i++){
                arr[i]=arr[i+1];
                // iter++;
            }
            // cout<<"Number of iteration to delete is "<<iter<<endl;
            size--;
            return val;
        }

        bool isEmpty(){
            return (size==0);
        }

        T get(int index){
            return arr[index];
        }

        int indexOf(T x){
            int index = -1;
            for(int i=0; i<size; i++){
                if(arr[i] == x){
                    index = i;
                    break;
                }
            }
            return index;
        }

        int size(){
            return size;
        }

        int capacity(){
            return length;
        }

        void display(){
            cout<<"[";
            for(int i=0; i<size; i++){
                cout<<arr[i]<<",";
            }
            cout<<"\b]";
            return;
        }

        T operator[](int index){
            return arr[index];
        }
    };
    
}

