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

//make cycle at position k
void makeCycle(ll* lhead, int k){
    node* curr = *lhead, *cyclenode = NULL;
    //make last node point to pos node
    int count = 0;
    while(curr->next){
        count++;
        if(count == k){
            cyclenode = curr;
        }
        curr= curr->next;
    }
    //list has ended
    curr->next = cyclenode;
    return;
}

// detech cycle - Flyod's algorithm
bool detectCycle(ll* lhead){
    node* slowptr = *lhead, *fastptr = *lhead;
    while(fastptr && fastptr->next){
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
        if(fastptr == slowptr){
            cout<<slowptr->data<<endl;

            return true;
        }
    }
    return false;
}


// detech cycle - Flyod's algorithm
void removeCycle(ll* lhead){
    node* slowptr = *lhead, *fastptr = *lhead;
    while(fastptr && fastptr->next){
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
        if(fastptr == slowptr){
            break;
        }
    }
    fastptr = *lhead;
    while(fastptr->next != slowptr->next){
        slowptr = slowptr->next;
        fastptr = fastptr->next;
    }
    slowptr->next = NULL;
}

int main(){
  ll* lhead = new ll;
    *lhead = NULL;
    append(lhead, 20);
    append(lhead, 40);
    append(lhead, 45);
    append(lhead, 30);
    append(lhead, 40);
    append(lhead, 45);
    append(lhead, 30);
    append(lhead, 40);
    append(lhead, 45);
    append(lhead, 30);
    display(*lhead);
  //  makeCycle(lhead, 6);
    if(detectCycle(lhead)){
        cout<<"\nCycle present in list";
    }
    else{
        cout<<"No cycle";
    }
    removeCycle(lhead);
    if(detectCycle(lhead)){
        cout<<"Cycle present in list";
    }
    else{
        cout<<"\nNo cycle";
    }
    display(*lhead);
    return 0;
}