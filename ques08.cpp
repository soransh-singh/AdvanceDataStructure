/*
    Evaluation of postfix expression
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

int op(int x, int y, char ch){
    if(ch=='+'){
        return x+y;
    }else if(ch=='-'){
        return x-y;
    }else if(ch=='*'){
        return x*y;
    }else if(ch=='/'){
        return x/y;
    }
}

int main(){
    stack<int> s;
    string str;
    cin>>str;
    for(auto ch:str){
        if(oprtr(ch)){
            int y=s.top();
            s.pop();
            int x=s.top();
            s.pop();
            int val = op(x,y,ch);
            s.push(val);
        }else{
            s.push(ch-48);
        }
    }

    cout<<s.top();
    return 0;
}
