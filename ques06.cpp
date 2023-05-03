/*
    Converting string into float without using 
    type conversion
*/ 
#include<bits/stdc++.h>

using namespace std;

void stringToFloat(string str){
    stack<int> s;
    float num; 
    bool isInvalid = false;
    bool deci = true;
    int deciPos=0;
    int n=str.length();

    int initial = (str[0]=='+'||str[0]=='-')?1:0;
    
    for(int i=initial; i<n; i++){
        if(str[i]>=48 and str[i]<=57){
            s.push(str[i]-48);
        }else if(str[i]==46 and deci){
            deciPos = n-i-1;
            if(str[i]==46){
                deci=false;
            }
        }else{
            isInvalid=true;
            break;
        }
    }

    if(isInvalid){
        cout<<"Invalid Input";
    }else{
        int i=0;
        while(!s.empty()){
            int temp = s.top();
            s.pop();
            num = temp*pow(10,i) + num;
            i++;
        }
        num = num/pow(10,deciPos);
        if(str[0]=='-'){
            num=num*-1;
        }
        cout<<num;
    }
}


int main(){
    
    string str;
    getline(cin,str);
    stringToFloat(str);
    return 0;
}