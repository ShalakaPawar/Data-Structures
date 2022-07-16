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

string reverse(string s){
    for(int i=0; i<s.size()/2+1; i++){
        char temp = s[i];
        s[i] = s[s.size()-i-1];
        s[s.size()-i-1] = temp;
    }
    for(int i=0; i< s.size(); i++){
        if(s[i] == ')')
            s[i] = '(';
        else if(s[i] == '(')
            s[i] = ')';
    }
    return s;
}

string to_prefix(string exp){
    // reverse the string
    exp = reverse(exp);
   // cout<<exp<<endl;
    string result="";
    // same as infix to postfix
    stack<char> stk;
    for(int i=0; i<exp.size(); i++){
        if(isoperator(exp[i])){
            //check precedence and then push to stack
                if(exp[i] == '('){
                    stk.push(exp[i]);
                }
                else if(exp[i] == ')'){
                    while(stk.top() != '('){
                        result += stk.top();
                        stk.pop();
                    }
                    // pop ( from stack
                    stk.pop();
                }
                else{
                    while(!stk.empty() && get_precedence(stk.top()) > get_precedence(exp[i])){
                        result +=stk.top();
                        stk.pop();
                    }
                    // push exp[i]
                    stk.push(exp[i]);
                }
            }
        
        else if(isoperand(exp[i])){
            //print the operands
            result +=exp[i];
        }
        else
            continue;
    }
    //if stack is not empty yet
    while(!stk.empty()){
        result +=stk.top();
        stk.pop();
    }
  //  cout<<result<<endl;
    return reverse(result);
}

int main(){
    string exp;
    //exp = "7+2";
    exp = "(a-b/c)*(a/k-1)";

    cout<<to_prefix(exp);
    return 0;
}