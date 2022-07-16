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
        newnode->next = *llhead;
        return;
    }
    node* currnode = *llhead;
    while (currnode->next != *llhead)
    {
        currnode = currnode->next;
    }
    //reached the end
    currnode->next = newnode;
    newnode->next = *llhead;
    return;
}

//delete
void deletion(ll* lhead, int val){
    //list is empty - return
    if(*lhead == NULL)
        return;
    node* currnode = *lhead, *prevnode = *lhead;
    // if list head is to be deleted
    if((*lhead)->data == val){
        currnode = *lhead;
        //make last node point to new head
        while(currnode->next != *lhead){
            currnode = currnode->next;
        }
        //reached the end
        currnode->next = (*lhead)->next;
        //free the head node
        currnode = *lhead;
        *lhead = (*lhead)->next;
        currnode->next = NULL;
        free(currnode);
        return;
    }
    currnode = currnode->next;
    while(currnode != *lhead && currnode->data != val){
        prevnode = currnode;
        currnode = currnode->next;
    }
     //value not present in list , reached end of list
    if (currnode == *lhead){
        return;
    }
    //found the node
   prevnode->next = currnode->next;
   currnode->next = NULL;
   free(currnode);
   return;
}

void display(ll llhead){
    cout<<"\nLinked list = ";
    if(llhead == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    node* currnode = llhead;
    cout<<currnode->data<<"\t";
    currnode = currnode->next;
    while (currnode != llhead){
        cout<<currnode->data<<"\t";
        currnode = currnode->next;
    }
    cout<<endl;
}

int main(){
    ll* lhead = new ll;
    *lhead = NULL;
    display(*lhead);
    append(lhead, 20);
    append(lhead, 40);
    append(lhead, 45);
    append(lhead, 30);
    display(*lhead);
    deletion(lhead, 20);
     display(*lhead);
    // append(lhead, 10);

    return 0;
}