/*
    // Define void store(Array &a, int n);
    // function to insert 1,2,3...n
    // it will be inserted in such a way that 
    // first odd number will be stored then even number.
*/
#include<iostream>
#include ".\headerFile\Array.h"

using namespace Arr;
using namespace std;

/*
void store(Array &arr, int n){
    int num;
    cout<<"Enter the elements one by one:\n";
    int oddInd=0;
    for(int i=1; i<=n; i++){
        cin>>num;
        if(num%2==0){
            arr.insert(num, arr.getSize());    
        }else{
            arr.insert(num, oddInd);
            oddInd++;
        }
    }
} 
*/
void store(Array<int> &arr, int n){
    int num;
    cout<<"Enter the elements one by one:\n";
    int oddInd=0;
    for(int i=1; i<=n; i++){
        num=i;
        if(num%2==0){
            arr.insert(num, arr.getSize());    
            arr.insert(num, arr.getSize());    
        }else{
            arr.insert(num, oddInd);
            oddInd++;
        }
    }
}


int main(){
    int n;
    cout<<"Enter number of elements in Array\n";
    do{
        cout<<"\t--Number Must be Even--\n";
        cin>>n;
    }while(n%2!=0);
    Array<int> arr(2*n);
    store(arr, n);
    arr.display();
    return 0;
}