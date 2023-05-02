/*
    Implementing fibonaci using stack;
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    stack<int> s;
    int num,n;
    cin>>num;
    n=num;
    int fib = 0;
    s.push(n);
    while(!s.empty()){
        n = s.top();
        s.pop();
        if(n>2){
            s.push(n-1);
            s.push(n-2);
        }else if(n==1 or n==2){
            fib = fib+1;
        }
    }
    cout<<"fibonacci numer at "<<num<<" is: "<<fib;
    return 0;
}