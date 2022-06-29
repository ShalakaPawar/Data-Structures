#include<bits/stdc++.h>
using namespace std;
// replace pi with 3.14 in string
void solution(string str){
    if(str.size()<= 1){
        cout<<str.substr(0, 1);
        return;
    }
        
    if("pi" == str.substr(0, 2)){
        cout<<"3.14";
        solution(str.substr(2));
    }
    else{
        cout<<str.substr(0, 1);
        solution(str.substr(1));
    }
       
}
int main(){
    string str="pippxxppiipi";
    solution(str);
    return 0;
}