#include<iostream>
#include<stack>
using namespace std;

int get_precedence(char opr){
    if(opr == '(')
        return 0;
    else if(opr == '^')
        return 3;
    else if(opr == '*' || opr == '/')
        return 2;
    else if(opr == '+' || opr == '-')
        return 1;
    else return -1;
}

bool isoperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '('|| c == ')'){
        return true;
    }
    return false;
}

bool isoperand(char c){
    if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' || c <= 'Z')){
        return true;
    }
    return false;
}

void to_postfix(string exp){
    stack<char> stk;
    for(int i=0; i<exp.size(); i++){
        if(isoperator(exp[i])){
            //check precedence and then push to stack
                if(exp[i] == '('){
                    stk.push(exp[i]);
                }
                else if(exp[i] == ')'){
                    while(stk.top() != '('){
                        cout<<stk.top();
                        stk.pop();
                    }
                    stk.pop();
                }
                else{
                    while(!stk.empty() && get_precedence(stk.top()) > get_precedence(exp[i])){
                        char t = stk.top();
                        stk.pop();
                        cout<<t;
                    }
                    // push exp[i]
                    stk.push(exp[i]);
                }
            }
        
        else if(isoperand(exp[i])){
            //print the operands
            cout<<exp[i];
        }
        else
            continue;
    }
    //if stack is not empty yet
    while(!stk.empty()){
        cout<<stk.top()<<"\t";
        stk.pop();
    }
    return;
}

int main(){
    string exp;
    //exp = "7+2";
    exp = "(a-b/c)*(a/k-1)";
    to_postfix(exp);
    return 0;
}