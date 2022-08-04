#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
public:
    int data = INT_MIN;
    Node* left  = NULL;
    Node* right = NULL;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
typedef Node* Btree;

// inorder traversal
void inorder(Btree bt){
    if(!bt){
        return;
    }
    inorder(bt->left);
    cout<<bt->data<<"\t";
    inorder(bt->right);
}


// preorder traversal
void preorder(Btree bt){
    if(!bt)
        return;
    cout<<bt->data<<"\t";
    preorder(bt->left);
    preorder(bt->right);
}


// postorder traversal
void postorder(Btree bt){
    if(!bt)
        return;
    postorder(bt->left);
    postorder(bt->right);
    cout<<bt->data<<"\t";
}

// insert in binary tree in level order
Node* insertLevelOrder(Btree* bt, int data){
    Node* newnode = new Node(data);
    if(*bt == NULL){
        *bt = newnode;
        return *bt;
    }
    queue<Node*> q;
    q.push(*bt);
    while(q.empty()==false){
        Node* currnode = q.front();
        q.pop();
        //if left child is empty - insert there
        if(currnode->left == NULL){
            currnode->left = newnode;
            return *bt;
        }
        else{
            q.push(currnode->left);
        }
        //if right is empty - insert
        if(currnode->right == NULL){
            currnode->right = newnode;
            return *bt;
        }
        else{
            q.push(currnode->right);
        }
        //else traverse again
    }
    return NULL;
}

// deletion from Binary tree
Node* deletion(Node* root, int data){
    if(root == NULL)
        return NULL;
    if(data < root->data)
        root->left = deletion(root->left, data);
    else if(data > root->data)
        root->right = deletion(root->right, data);
    else{
        Node* tbd = root;
        // data same as root
        //if root has no children
        if(root->left == NULL && root->right == NULL){
            delete tbd;
            return NULL; 
        }
        // root has one child
        else if(root->right == NULL){
            Node* newroot = root->left;
            delete tbd;
            return newroot;
        }
        else if(root->left == NULL){
            Node* newroot = root->right;
            delete tbd;
            return newroot;
        }

        // root has 2 children - replace with inorder predecessor
        Node* q = root->right, *r = root;
        while(q->left){
            r = q;
            q = q->left;
        }
        if(r != root)
            r->left = q->right;
        else
            r->right = q->right;
        //replace root value with q-value
        root->data = q->data;
        delete q;
        return root;
    }
    return root;
}

// inorder traversal without recursion
void inorder_recursion(Node* root){
    stack<Node*> stk;
    Node* curr = root;
    while(curr != NULL || stk.empty() == false){
        while(curr){
            stk.push(curr);
            curr = curr->left;
        }
        curr = stk.top();
        stk.pop();
        cout<<curr->data<<"\t";
        curr = curr->right;
    }
    return;
}

// find the index of the root from preorder in inorder
int search(int* inorder, int start, int end, int root){
    for(int i=start; i<= end; i++){
        if(inorder[i] == root)
            return i;
    }
    return -1;
}

int preIndex=0;
// get postorder from inorder and preorder
void print_postorder(int* inorder, int* preorder, int start, int end){
    if(start > end)
        return;
    int inorderIndex = search(inorder, start, end, preorder[preIndex++]);
    print_postorder(inorder, preorder, start, inorderIndex-1);
    print_postorder(inorder, preorder, inorderIndex+1, end);
    cout<<inorder[inorderIndex]<<"\t";
}


//Binary Search Tree
void post_from_pre(int* preorder, int n, int lbound, int ubound, int currindex){
    if(currindex == n || preorder[currindex] < lbound || preorder[currindex] > ubound)
        return;
    int val = preorder[currindex];
    currindex+=1;
    //left subtree
    post_from_pre(preorder, n, lbound, val, currindex);
    post_from_pre(preorder, n, val, ubound, currindex);
    cout<<val<<"\t";
    return;
}

void wrapper(int* preorder, int n){
    int index=0;
    post_from_pre(preorder, n,INT_MIN, INT_MAX, index);
    return;
}

int main(){
    Btree bt;
    Node* n = new Node(50);
    n->left = new Node(30);
    n->left->left = new Node(20);
    n->left->right = new Node(40);
    n->left->right->left = new Node(35);
    n->left->right->right = new Node(45);
    n->right = new Node(60);
   // n->right->left = new Node(60);
    n->right->right = new Node(80);
    bt = n;
    cout<<"\nInorder Traversal: ";
    inorder(bt);
    
   // bt = insertLevelOrder(&bt, 12);

    // bt = deletion(bt, 20);
    // cout<<"\nInorder Traversal: ";
    // inorder(bt);

    
    //bt = deletion(bt, 30);
    // cout<<"\nInorder Traversal: ";
    // inorder_recursion(bt);

    
    // bt = deletion(bt, 50);
    // cout<<"\nInorder Traversal: ";
    // inorder(bt);

    // cout<<"\nPreorder Traversal: ";
    // preorder(bt);
    
    // cout<<"\nPostorder Traversal: ";
    // postorder(bt);
    cout<<"\nPostorder: ";
    // int arr[] = {4, 2, 5, 1, 3, 6};
    // int pre[] = {1, 2, 4, 5, 3, 6};
    // int len = sizeof(arr)/sizeof(arr[0]);
    // print_postorder(arr, pre, 0, len - 1);

    int pre[] = { 40, 30, 35, 80, 100 };
  
    int size = sizeof(pre) / sizeof(pre[0]);
  
    // Calling function
    wrapper(pre, size);
    return 0;
}