/*
    Converting string into float without using 
    type conversion
*/ 
#include<bits/stdc++.h>

using namespace std;

int main(){
    stack<int> s;
    string str;
    cin>>str;
    float num; 
    bool isInvalid = false;
    bool deci = true;
    int deciPos=0;
    int n=str.length();
    
    for(int i=0; i<n; i++){
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
        cout<<num;
    }
    return 0;
}