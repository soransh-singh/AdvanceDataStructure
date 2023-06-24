#include<bits/stdc++.h>

using namespace std;

void printArray(int a[], int low, int high){
    for(int i=low; i<=high; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int search(int a[], int n, int x){
    int low=0, high=n-1, mid;
    if(x>=a[low] and x<=a[high]){
        while(low<=high){
            printArray(a, low, high);
            int denom = a[high] - a[low];
            if(denom==0){
                mid=low;
            }else{
                mid = low + (x - a[low])*(high - low)/denom;
            }
            cout<<"mid: "<<mid<<" "<<a[mid]<<endl;
            if(a[mid]==x){
                return mid;
            }else if(x<a[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
            
            
        }
    }
    return -1;
}

int main(){
    // int arr[] = {1 ,3, 5, 7, 9, 11, 13, 14, 16, 18, 20, 23, 25, 27, 29};
    int arr[] = {12, 23, 45, 64, 75, 78, 99};
    int n = sizeof(arr)/sizeof(n);
    int x;
    cin>>x;
    cout<<"Element is present at position: "<<search(arr, n, x);
    return 0;
}