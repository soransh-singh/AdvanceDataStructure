#include<iostream>
#include ".\headerFile\Stack.h"

using namespace std;
using namespace St;

int main(){
    StackArr<int> s1(10);
    for(int i=0; i<10; i++){
        s1.push(i*10);
        s1.display();
    }
    s1.display();
    for(int i=0; i<4; i++){
        s1.pop();
    }
    s1.display();
}