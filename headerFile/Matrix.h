#include<iostream>
#include<stdexcept>

using namespace std;

namespace Mat{
    /* Class: Matrix*/
    class Matrix{
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
        if(rows != B.rows || cols != B.cols){
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