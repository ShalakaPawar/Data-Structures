#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int prefix_eval(string exp){
    stack<int> operand_stk;
    for(int i=exp.size()-1; i>=0; i--){
        //if operand put in stack
        if(exp[i] >= '0' && exp[i] <= '9'){
            operand_stk.push(exp[i]-'0');
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            //pop two  numbers and push back the result
            int num1 = operand_stk.top();
            operand_stk.pop();
            int num2 = operand_stk.top();
            operand_stk.pop();
            switch (exp[i])
            {
            case '+':
                operand_stk.push(num1+num2);
                break;
            case '-':
                operand_stk.push(num1-num2);
                break;
            case '*':
                operand_stk.push(num1*num2);
                break;
            case '/':
                operand_stk.push(num1/num2);
                break;
            case '^':
                operand_stk.push(pow(num1, num2));
                break;;
            default:
                break;
            }
        }
        else
            continue;
    }
    return operand_stk.top();
}

int main(){
    string exp = "*2+7/55";
    cout<<prefix_eval(exp);
    return 0;
}