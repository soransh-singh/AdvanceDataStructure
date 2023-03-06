#include<iostream>
#include<stdexcept>

using namespace std;

namespace Arr{
    /* Class: Array */
    class Array{
        int *arr;
        int size, length;
        public:
        Array(int n){
            arr = new int[n];
            length = n;
            size=0;
        }

        void insert(int x, int index){
            if(size == length){
                throw invalid_argument("Array is Full");
            }
            if(index > size){
                throw invalid_argument("Invalid Index");
            }
            int iter = 0;
            for(int i=size; i>index; i--){
                arr[i]= arr[i-1];
                iter++;
            }
            cout<<"Number of movement to input "<<x<<" is "<<iter<<endl;
            arr[index]= x;
            size++;
        }

        int del(int index){
            
            if(size==0){
                throw invalid_argument("Array is Empty");
            }

            if(index>= size){
                throw invalid_argument("Invalid Index");
            }
            
            int iter = 0;
            int val = arr[index];
            for(int i=index; i<size; i++){
                arr[i]=arr[i+1];
                iter++;
            }
            cout<<"Number of iteration to delete is "<<iter<<endl;
            size--;
            return val;
        }

        bool isEmpty(){
            return (size==0);
        }

        int get(int index){
            return arr[index];
        }

        int indexOf(int x){
            int index = -1;
            for(int i=0; i<size; i++){
                if(arr[i] == x){
                    index = i;
                    break;
                }
            }
            return index;
        }

        int getSize(){
            return size;
        }

        void display(){
            cout<<"[";
            for(int i=0; i<size; i++){
                cout<<arr[i]<<",";
            }
            cout<<"\b]";
            return;
        }
    };

    /* Class: Matrix*/
    class Matrix
    {
        public:
            int rows;
            int cols;
            int** arr;
            Matrix(int r,int c);
            Matrix(int r);
            void read();
            void print();
            Matrix add(Matrix B);
            Matrix mul(Matrix B);
    };

    Matrix::Matrix(int r){
        rows = r;
        cols = r;
        arr = new int*[rows];
        for(int i=0; i<rows; i++){
            arr[i] = new int[cols];
        }
    }

    Matrix::Matrix(int r,int c){
        rows = r;
        cols = c;
        arr = new int*[rows];
        for(int i=0; i<rows; i++){
            arr[i] = new int[cols];
        }
    }

    void Matrix::read(){
        cout<<"Enter a matrix of order "<<rows<<"x"<<cols<<endl;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cin>>arr[i][j];
            }
        }
    }

    void Matrix::print(){
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cout<<arr[i][j]<<"\t";
            }
            cout<<endl;
        }
    }

    Matrix Matrix::add(Matrix B){
        if(rows != B.rows or cols != B.cols){
            throw invalid_argument("Addition Invalid ");
        }
        Matrix C(rows, cols);
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                C.arr[i][j] = arr[i][j] + B.arr[i][j];
            }
        }
        return C;
    }

    Matrix Matrix::mul(Matrix B){
        if(cols != B.rows){
            throw invalid_argument("Multiplication Invalid ");
        }
        Matrix C(rows, cols);
        for(int i=0; i<rows; i++){
            for(int j=0; j<B.cols; j++){
                C.arr[i][j] = 0;
                for(int k=0; k<cols; k++){
                    C.arr[i][j] += arr[i][k]*B.arr[k][j];
                }
            }
        }
        return C;
    }
    
}

