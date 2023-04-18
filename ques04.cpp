/*
  - Conversion from infix to postfix expression
*/ 

#include<iostream>
#include "Stack.h"

using namespace std;
using namespace Stack;

int precedence(char ch){
    if(ch == '/'){
        return 4;
    }else if(ch == '*'){
        return 3;
    }else if(ch == '+' || ch == '-'){
        return 2;
    }
    return 1;
}

bool oprtr(char ch){
    return (ch == '*' || ch== '+' || ch == '-' || ch == '/');
}

int main(){
    string str;
    cin>>str;
    int n= str.length();
    StackArr<char> s1(20);
    
    str = str + ')';
    s1.push('(');
    char y;
    string p="";
    for(int i=0; i<str.length(); i++){
        char x = str[i];
        if(x == '('){
            s1.push(x);
        }else if(x == ')'){
            y=s1.pop();
            while(y != '('){
                p = p+y;
                y=s1.pop();
            }
        }else if (oprtr(x)){
            while(oprtr(y) and precedence(y) >= precedence(x)){
                p = p + y;
                y= s1.pop();
            }
            s1.push(y);
            s1.push(x);
        }else if(x == '1' || x == '2' || x == '3' || x == '4'|| x == '5' || x == '6'||x == '7' || x == '8'||x == '9' || x == '0'){
            p = p + x;
        }
    }
    cout<<p;
    return 0;
}

