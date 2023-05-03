/*
    Write a Program to tokenize a string;
    input: "12+3"
    output: {"12", "+", "3"}
*/

#include<bits/stdc++.h>

using namespace std;

bool oprtr(char x){
    if(x=='+' or x=='-' or x=='*' or x=='/' or x=='{' or x=='}' or x=='(' or x==')'){
        return true;
    }else {
        return false;
    }
}

int main(){
    string str;
    getline(cin, str);
    str +='\0';
    queue<string> q;
    // string q[n];
    int i=0;
    while(str[i]!='\0'){
        if(oprtr(str[i])){
            string temp="";
            temp.append(1, str[i]);
            // cout<<temp<<", ";
            q.push(temp);
        }else if(str[i]==' '){

        }else{
            string temp="";
            bool key=true;
            do{
                temp.append(1, str[i]);
                if(str[i+1]!='\0'){
                    i++;
                }else{
                    key=false;
                    break;
                }
            }while(!(oprtr(str[i])or str[i]==' '));
            if(key){
            i--;
            }
            q.push(temp);
        }
        i++;
    }

    cout<<"{";
    while(!q.empty()){
        cout<<"\""<<q.front()<<"\", ";
        q.pop();
    }
    cout<<"\b\b}";
    return 0;
}