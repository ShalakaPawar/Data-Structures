#include "ll.h"

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
        currnode->next = NULL;
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
   currnode->next = NULL;
   free(currnode);
   return;
}

// reverse a linked list
void reverse(ll* lhead){
    if(*lhead == NULL)
        return;
    node *curr, *next, *prev;
    curr = *lhead;
    next = (*lhead)->next;
    prev = NULL;
    while(curr){
        curr->next = prev;
        prev = curr;
        curr = next;
        if (curr)
            next = curr->next;
    }
    *lhead = prev;
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
     display(*lhead);
    // append(lhead, 10);

    return 0;
}