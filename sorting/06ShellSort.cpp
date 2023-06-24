#include<iostream>

using namespace std;

void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void shellSort(int a[], int n){
    // int gap=n/2;
    int gap=1;
    while(gap < n/3){
        gap=gap*3 +1;
    }
    while(gap>=1){
        for(int i=gap; i<n; i++){
            int x=a[i];
            int j=i;
            while(j>=gap && a[j-gap]>x){
                a[j]=a[j-gap];
                j=j-gap;
            }
            a[j]=x;
        }
        cout<<"Gap: "<<gap<<endl;
        printArray(a,n);
        gap=(gap-1)/3;
        // gap/=2;
    }
}



int main(){
    // int arr[]={23,46,89,43,57,9,64,32,5,8,9,54,32,57,90,64,24,67,90,43,98,2,46};
    int arr[]={23,77,45,54,21,33};
    int n = sizeof(arr)/sizeof(int);
    printArray(arr, n);
    shellSort(arr, n);
    printArray(arr, n);
    return 0;

}