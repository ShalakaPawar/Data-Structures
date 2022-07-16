
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
        cout<<"Node created"<<endl;
    }
};

typedef node* ll;

// append - add elements to list
void append(ll* llhead, int val){
    node* newnode = new node(val);
    
    //list is empty
    if(*llhead == NULL){
        *llhead = newnode;
        return;
    }
    node* currnode = *llhead;
    while (currnode->next != NULL)
    {
        currnode = currnode->next;
    }
    //reached the end
    currnode->next = newnode;
    return;
}


void display(ll llhead){
    cout<<"\nLinked list = ";
    if(llhead == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    node* currnode = llhead;
    while (currnode != NULL){
        cout<<currnode->data<<"\t";
        currnode = currnode->next;
    }
    cout<<endl;
}

void appendKNodes(ll* lhead, int k){
    if(*lhead == NULL)
        return;
    node* frontptr = *lhead, *backptr =*lhead;
    int count = 0;
    while (backptr->next != NULL){
        if(count >= k)
            frontptr = frontptr->next;
        backptr= backptr->next;
        count++;
    }
    if (count < k)
        return;
    backptr->next = *lhead;
    (*lhead) = frontptr->next;
    frontptr->next = NULL;
    return;
}

int main(){
    ll* lhead = new ll;
    *lhead = NULL;
    append(lhead, 20);
    append(lhead, 40);
    append(lhead, 45);
    append(lhead, 30);
    display(*lhead);
    appendKNodes(lhead, 1);
     display(*lhead);
//     reverse(lhead);
//  //   deletion(lhead, 30);
//      display(*lhead);
//     // append(lhead, 10);

    return 0;
}