
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

ll* merge_sorted(ll* l1, ll* l2){
    if(*l1 == NULL)
        return l2;
    if(*l2 == NULL)
        return l1;
    //add both the lists in l1
    ll* newList = new ll;
    node* curr = new node(-1); 
    *newList = curr;
    node* curr1 = *l1, *curr2 = *l2;
    //while both the list exist
    while(curr1 && curr2){
        if(curr1->data < curr2->data){
            curr->next = curr1;
            curr1 = curr1->next;
        }
        else{
            curr->next = curr2;
            curr2 = curr2->next;
        }
        curr = curr->next;
        curr->next = NULL;
    }
    //append th remaining nodes of the list 
    // list 1 nodes are remaining
    if(!curr1){
        while(curr1){
            curr->next = curr1;
            curr1 = curr1->next;
            curr = curr->next;
            curr->next = NULL;
        }
    }
    // list 2 nodes are remaining
    if(!curr2){
        while(curr1){
            curr->next = curr2;
            curr2 = curr2->next;
            curr = curr->next;
            curr->next = NULL;
        }
    }
    return &((*newList)->next);
}

int main(){
    ll* l1 = new ll;
    *l1 = NULL;
    append(l1, 5);
    append(l1, 15);
    append(l1, 33);
    append(l1, 55);
    display(*l1);

    ll* l2 = new ll;
    *l2 = NULL;
    append(l2, 10);
    append(l2, 35);
    append(l2, 43);
    append(l2, 65);
    display(*l2);
    ll* newlist = merge_sorted(l1, l2);
    display(*newlist);
//     reverse(lhead);
//  //   deletion(lhead, 30);
//      display(*lhead);
//     // append(lhead, 10);

    return 0;
}