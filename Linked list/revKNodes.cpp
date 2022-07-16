
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
/*
bool hasKNodes(ll lhead, int k){
    if(lhead == NULL)
        return true;
    node* curr = lhead;
    for(int i=0; i<k; i++){
        if(!curr){
            return false;
        }
    }
    return true;
}

node* getNewHead(ll* lhead, int n){
    if(*lhead == NULL){
        return *lhead;
    }
    node* curr = *lhead;
    for(int i=0; i<n; i++){
        curr = curr->next;
    }
    return curr;
}

// reverse k nodes
ll* reverseKNodes(ll* lhead, int k){
    if(k==0 || k==1)
        return lhead;
    //check it has k nodes 
    node* newhead = *lhead;
    if(hasKNodes(*lhead, k)){
        // get the new head - last node
        newhead = getNewHead();
    }
    return &newhead;
}
*/
 bool hasKNodes(ll head, int k){
        node* curr = head;
        for(int i=0;i<k;i++){
            // not enough for reversal
            if(!curr)
                return false;
            curr = curr->next;
        }   
        return true;
}
node* reverseknodes(ll lhead, int k){
    if(!lhead || k <= 1 ||!hasKNodes(lhead, k))
            return lhead;
    node *next, *prev = NULL;
    int c=0;
    node* curr = lhead;
    while(curr != NULL && c < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        c++;
    }
    if(next != NULL)
        lhead->next = reverseknodes(next, k);
    return prev;
}

int main(){
    ll* lhead = new ll;
    *lhead = NULL;
    append(lhead, 20);
    append(lhead, 40);
    append(lhead, 45);
    append(lhead, 30);
    display(*lhead);
    *lhead =reverseknodes(*lhead, 2);
     display(*lhead);
//     reverse(lhead);
//  //   deletion(lhead, 30);
//      display(*lhead);
//     // append(lhead, 10);

    return 0;
}