#include<iostream>
#include<stack>
using namespace std;

void reverse_string(string s){
    string word="";
    stack<string> stk;
    for(auto i = s.begin(); i<=s.end(); i++){
        //if space encountered push in stack
        if(isspace(*i)){
            stk.push(word);
            word="";
        }
        word += *i;
    }
    stk.push(word);
    while(stk.empty() == false){
        cout<<stk.top()<<"\t";
        stk.pop();
    }
    return;
}

int main(){
    
    string str = "Hey, how are you doing?";
    reverse_string(str);

}