/*
    Converting string into float without using 
    type conversion
*/ 
#include<bits/stdc++.h>

using namespace std;

float stringToFloat(string str){
    stack<int> s;
    float num=0; 
    bool deci = true;
    int deciPos=0;
    int n=str.length();

    int initial = (str[0]=='+'||str[0]=='-')?1:0;
    
    for(int i=initial; i<n; i++){
        if(str[i]>=48 and str[i]<=57){
            s.push(str[i]-48);
        }else if(str[i]==46 and deci){
            deciPos = n-i-1;
            deci=false;
        }else{
            throw runtime_error("Invalid Input");
        }
    }

    int i=0;

    //Putting values
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        num = temp*pow(10,i) + num;
        i++;
    }
    //Puting decimal at right position
    num = num/pow(10,deciPos);
    
    //Putting negative sign
    if(str[0]=='-'){
        num=num*-1;
    }
    return num;
}


int main(){
    try{
        cout<<stringToFloat("12.3");
    }catch(exception& e){
        cerr<<"Invalid Input"<<'\n';
    }
    
    return 0;
}