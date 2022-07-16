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
void even_after_odd(ll* lhead){
    if(*lhead == NULL)
        return;
    node* odd = *lhead;
    node* even_start = (*lhead)->next;
    node* even = (*lhead)->next;
    while (odd && even && odd->next && even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = even_start;
    if(even)
        even->next = NULL;
    return;
}

int main(){
    ll* l1 = new ll;
    *l1 = NULL;
    append(l1, 1);
    append(l1, 2);
    append(l1, 3);
    append(l1, 4);
    append(l1, 5);
    append(l1, 6);
    append(l1, 7);
   // append(l1, 8);
    display(*l1);
    even_after_odd(l1);
    display(*l1);
    return 0;
}