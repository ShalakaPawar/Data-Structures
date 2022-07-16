#include<iostream>
#include<stack>
using namespace std;

void insert_at_bottom(stack<int> &s, int ele){
    if(s.empty() == true){
        s.push(ele);
        return;
    }
    int n = s.top();
    s.pop();
    insert_at_bottom(s, ele);
    s.push(n);
    return;
}

//reverse  a stack using recursion
void rev_stack(stack<int> &stk){
    if(stk.empty() == true)
        return;
    int n = stk.top();
    stk.pop();
    rev_stack(stk);
    insert_at_bottom(stk, n);
    //
    //cout<<n<<"\n";
    return;
}
 
int main(){
    stack<int> s1;
    s1.push(6);
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);
    // cout<<"\nStack: ";
    // while(s1.empty() == false){
    //     cout<<s1.top()<<"\t";
    //     s1.pop();
    // }
    rev_stack(s1);
    cout<<"\nStack: ";
    while(s1.empty() == false){
        cout<<s1.top()<<"\t";
        s1.pop();
    }
    return 0;
}