#include<iostream>

class Node{
public:
    int data{0};
    Node* left;

};

class BTree{
    int a;
};

int main(){
    Node a = Node();
    a.data = 10;
    std::cout<<a.data;
    return 0;
}