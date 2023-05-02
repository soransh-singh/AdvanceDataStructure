/* 
    Infix To Postfix Expression
*/ 
#include<bits/stdc++.h>

using namespace std;

bool oprtr(char x){
    if(x=='+' or x=='-' or x=='*' or x=='/'){
        return true;
    }else {
        return false;
    }
}

bool oprnd(char x){
    if(x>=48 and x<=57){
        return true;
    }else {
        return false;
    }
}

int precedence(char x){
    if(x=='/' or x=='*'){
        return 2;
    }else if(x=='+' or x=='-'){
        return 1;
    }
}

int main(){
    stack<char> s;
    string str;
    cin>>str;
    char y;
    string p;
    str = str + ')';
    s.push('(');
    for(auto x:str){
        if(x == '('){
            s.push(x);
        }else if(x == ')'){
            y= s.top();
            s.pop();
            while(y != '('){
                p = p + y;
                y = s.top();
                s.pop();
            }
        }else if(oprtr(x)){
            y=s.top();
            s.pop();
            while(oprtr(y) and precedence(y)>=precedence(x)){
                p = p +y;
                y=s.top();
                s.pop();
            }
            s.push(y);
            s.push(x);
        }else if(oprnd(x)){
            p = p+x;
        }
    }

    cout<<p;
    
    return 0;
}
