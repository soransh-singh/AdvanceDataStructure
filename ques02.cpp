#include<iostream>
#include "Array.h"

using namespace Arr;
using namespace std;

int main(){
    Matrix M1(2,2), M2(2,2);
    M1.read();
    M1.print();
    M2.read();
    M2.print();
    Matrix M3 = M1.mul(M2);
    M3.print();
    return 0;
}