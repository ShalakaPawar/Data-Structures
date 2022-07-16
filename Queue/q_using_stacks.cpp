#include<iostream>
#include<stack>
using namespace std;
/*
    Implement queue using 2 stacks
*/
class Queue{
    std::stack<int> s1;
    std::stack<int> s2;
public:
    bool empty(){
        if(s1.empty() && s2.empty())
            return true;
        return false;
    }

    void enqueue(int data){
        s1.push(data);
    }

    int dequeue(){
        if(empty())
            return -1;
        //s2 contains elements
        if(s2.empty()){
             // if s2 is empty
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        //all elements from s1 are in s2
        int res = s2.top();
        s2.pop();
        return res;
    }
};



int main(){
    Queue* q= new Queue;
    cout<<"dequeue = "<<q->dequeue()<<endl;
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->enqueue(40);
    q->enqueue(50);
    cout<<"dequeue = "<<q->dequeue()<<endl;

}