/*
Experimental:
to See example of StackQueue.h
*/ 

#include<bits/stdc++.h>
#include ".\headerFile\StackQueue.h"

using namespace std;
using namespace SQueue;


int main(){
    StackQueue<int> s(10);
    s.insert(54);
    s.insert(55);
    s.insert(53);
    s.insert(2);
    s.insert(5);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.displayQueue();
    s.displayStack();
    return 0;
}
