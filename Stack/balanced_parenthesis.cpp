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

bool checkBalanceParenthtesis(string exp){
    stack<char> stk;
    for(auto c: exp){
        if(c == '{' || c== '[' || c == '('){
            stk.push(c);
        }
        else if (c == '}' || c == ']' || c==')'){
            if(stk.empty())
                return false;
            char p = stk.top();
            //match not found
            if(!checkMatch(p, c))
                return false;
            stk.pop();
        }
        else
            continue;
    }
    if(stk.empty() == false)
        return false;
    return true;
}

int main(){
    string exp = "([(){[][]])";   
    cout<<checkBalanceParenthtesis(exp)<<endl;
    return 0;
}