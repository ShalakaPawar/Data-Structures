#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s1;
    cout<<s1.top()<<"\t";
    s1.push(8);
    s1.push(4);
    s1.push(0);
    while(s1.empty() == false){
        cout<<s1.top()<<"\t";
        s1.pop();
    }
    return 0;
}