#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = prev = NULL;
        cout<<"Node created"<<endl;
    }
};

typedef node* ll;

// append - add elements to list
void append(ll* llhead, int val);
void deletion(ll* lhead, int val);
void reverse(ll* lhead);
void display(ll llhead);

//pos = 1 -? head
//pos > length then append
void insert(ll* lhead,int val,  int pos){
    node* curr = *lhead, *prev = NULL;
    node* newnode = new node(val);
    if(pos == 1){
        //at the beginning
        newnode->next = *lhead;
        newnode->prev = (*lhead)->prev;
        (*lhead)->prev = newnode;
        *lhead = curr;
        return;
    }
    int count = 0;
    while (curr){
        prev = curr;
        curr = curr->next;
        if(count ==pos){
            //found the position
            break;
        }
        count++;
    }
    prev->next = newnode;
    newnode->next = curr;
    curr->prev = newnode;
    newnode->prev = prev;
}

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
    newnode->prev = currnode;
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
        *lhead = (*lhead)->next;
        (*lhead)->prev = NULL;
        currnode->next = currnode->prev = NULL;
        free(currnode);
        return;
    }
    while(currnode && currnode->data != val){
        prevnode = currnode;
        currnode = currnode->next;
    }
     //value not present in list , reached end of list
    if (!currnode){
        return;
    }
    //found the node
   prevnode->next = currnode->next;
   prevnode->next->prev = prevnode;
   currnode->next = currnode->prev = NULL;
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
    while (currnode != NULL){
        cout<<currnode->data<<"\t";
        currnode = currnode->next;
    }
    cout<<endl;
}
int main(){
    return 0;
     ll* lhead = new ll;
    *lhead = NULL;
    display(*lhead);
    append(lhead, 20);
    // append(lhead, 40);
    // append(lhead, 45);
    // append(lhead, 30);
    display(*lhead);
    reverse(lhead);
 //   deletion(lhead, 30);
}