
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

// calculate the length
int getLength(ll lhead){
    node* curr = lhead;
    int len=0;
    while(curr){
        len++;
        curr = curr->next;
    }
    return len;
}

int intersection_point(ll l1, ll l2){
    if(!l1 || !l2)
        return 0;
    int len1 = getLength(l1);
    int len2 = getLength(l2);
    node *start1 = l1, *start2 = l2;
    if(len1 > len2){
        for(int i=0; i<abs(len1-len2); i++){
            start1 = start1->next;
        }
    }else if(len1 < len2){
        for(int i=0; i<abs(len1-len2); i++){
            start2 = start2->next;
        }
    }
    //now both pointer are a same length
    while(start1 != start2){
        start1 = start1->next;
        start2 = start2->next;
    }
    return start1->data;
}


int main(){
    ll* l1 = new ll;
    *l1 = NULL;
    append(l1, 20);
    append(l1, 40);
    append(l1, 45);
    append(l1, 30);
    append(l1, 180);
    append(l1, 240);
    append(l1, 645);
    append(l1, 930);
    append(l1, 780);
    ll* l2 = new ll;
    *l2 = NULL;
    append(l2, 65);
    append(l2, 90);
    node *l = (*l2)->next;
    append(l2, 110);
    l = l->next;
    append(l2, 5);
    l = l->next;
    append(l2, 230);
    l->next = (*l1)->next->next->next;
    cout<<"\nLength = "<<getLength(*l2);
    display(*l2);
    display(*l1);
    cout<<"\nIntersection point = "<<intersection_point(*l1, *l2)<<endl;
//     reverse(lhead);
//  //   deletion(lhead, 30);
//      display(*lhead);
//     // append(lhead, 10);

    return 0;
}