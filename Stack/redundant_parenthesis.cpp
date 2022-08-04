#include<iostream>
#include<stack>
using namespace std;

//one being opening bracket
//two - closing bracket
bool checkMatch(char one, char two){
    if((one == '(' && two ==')') || (one == '[' && two ==']') || (one == '{' && two =='}'))
        return true;
    return false;
}


bool isoperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/'){
        return true;
    }
    return false;
}

bool checkRedundantParenthtesis(string exp){
    stack<char> stk;
    for(auto c: exp){
        if(c == '{' || c== '[' || c == '(' || isoperator(c)){
            stk.push(c);
        }
        else if (c == '}' || c == ']' || c==')'){
            if(stk.empty() || !isoperator(stk.top()))
                return true;
            while(!checkMatch(stk.top(), c)){
                stk.pop();
            }    
            stk.pop();
        }
        else
            continue;
    }
    if(stk.empty() == false)
        return true;
    return false;
}

int main(){
    string exp = "(a+b)()";   
    if(checkRedundantParenthtesis(exp))
        cout<<"Redundant"<<endl;
    else
        cout<<"Not Redundant"<<endl;
    return 0;
}