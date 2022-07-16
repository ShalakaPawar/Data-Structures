#include<iostream>
#include<stack>
using namespace std;
class Queue{
public:
    int front, back;
    int capacity;
    int size;
    int* array;
};

Queue* createQueue(int cap){
    Queue* Q = new Queue;
    Q->front = Q->back = -1;
    Q->size = 0;
    Q->capacity = cap;
    Q->array = new int [Q->capacity];
    return Q;
}

int size(Queue* Q){
    return Q->size;
}

int frontElement(Queue* Q){
    return Q->array[Q->front];
}

int backElement(Queue* Q){
    return Q->array[Q->back];
}

bool isEmpty(Queue* Q){
    return (Q->size == 0);
}

bool isFull(Queue* Q){
    return Q->size == Q->capacity;
}

void enqueue(Queue* Q, int ele){
    if(isFull(Q))
        return;
   // Q->back++;
   Q->back= (Q->back+1)%Q->capacity;
    Q->array[Q->back] = ele;
    //if queue was empty
    if(isEmpty(Q))
        Q->front = Q->back;
    Q->size++;
    return;
}

int dequeue(Queue* Q){
    if (isEmpty(Q))
        return -1;
    int res = Q->array[Q->front];
    if(Q->front == Q->back){
        Q->front= Q->back = -1;
        Q->size= 0;
    }
    else{
        Q->front= (Q->front+1)%Q->capacity;
        Q->size = -1;
    }
    return res;
}

//
//  Reverse the queue
//
void reverseQueue(Queue* Q){
    if(isEmpty(Q))
        return;
    stack<int> stk;
    while(!isEmpty(Q)){
        stk.push(dequeue(Q));
    }
    while(!stk.empty()){
        enqueue(Q, stk.top());
        stk.pop();
    }
    return;
}


int main(){
    Queue* q= new Queue;
    q = createQueue(10);
    cout<<isEmpty(q)<<endl;
     //cout<<"dequeue = "<<dequeue(q)<<endl;
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    // cout<<"dequeue = "<<dequeue(q)<<endl;
    // cout<<"dequeue = "<<dequeue(q)<<endl;
    // cout<<"dequeue = "<<dequeue(q)<<endl;
    // cout<<isEmpty(q)<<endl;

    
    reverseQueue(q);
     cout<<"dequeue = "<<dequeue(q)<<endl;
    cout<<"dequeue = "<<dequeue(q)<<endl;
    cout<<"dequeue = "<<dequeue(q)<<endl;
     cout<<"dequeue = "<<dequeue(q)<<endl;
    cout<<"dequeue = "<<dequeue(q)<<endl;
    cout<<"dequeue = "<<dequeue(q)<<endl;
    return 0;
}