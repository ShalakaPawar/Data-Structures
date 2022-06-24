#include<iostream>

// rectangle pattern
void pattern1(int row, int col){
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++)
            std::cout<<"*";
        std::cout<<std::endl;
    }
}

//hollow rectangle pattern
void pattern2(int row, int col){
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++)
            if (j == 0 || j == col-1 || i == 0 || i == row-1)
                std::cout<<"*";
            else
                std::cout<<" ";
        std::cout<<std::endl;
    }
}

//inverted half pyramid
void pattern3(int row){
    for (int i=0; i< row; i++){
        for (int j=0;j< row-i; j++)
            std::cout<<"*";
        std::cout<<std::endl;
    }
}

void pattern4(int row){
    for (int i=0; i< row; i++){
        for (int j=row-1-i;j>0; j--)
            std::cout<<" ";
        for (int j=0;j< i+1; j++)
            std::cout<<"*";
        std::cout<<std::endl;
    }
}

//numbers half pyramid
void pattern5(int row){
    for (int i=0; i< row; i++){
        for (int j=0;j< i+1; j++)
            std::cout<<i+1;
        std::cout<<std::endl;
    }
}

// floyd's triangle
void pattern6(int row){
    int n = 1;
    for (int i=0; i< row; i++){
        for (int j=0;j< i+1; j++)
            std::cout<<n++<<" ";
        std::cout<<std::endl;
    }
}

// butterfly pattern
void pattern7(int n){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < i+ 1; j++)
            std::cout<<"*";
        for (int j = 2*n; j > 2*(i+1); j--)
            std::cout<<" ";
        for (int j = 0; j < i+ 1; j++)
            std::cout<<"*";
        std::cout<<std::endl;
    }
    for(int i = 0; i < n; i++){
        for (int j=0;j< n-i; j++)
            std::cout<<"*";
        for (int j = 0; j < 2*i; j++)
            std::cout<<" ";
        for (int j = 0; j < n-i; j++)
            std::cout<<"*";
        std::cout<<std::endl;
    }
}

int main(){
    pattern1(4, 5);
    std::cout<<std::endl;
    pattern2(4, 5);
    std::cout<<std::endl;
    pattern3(10);
    std::cout<<std::endl;
    pattern4(5);
    std::cout<<std::endl;
    pattern5(7);
    std::cout<<std::endl;
    pattern6(7);
    std::cout<<std::endl;
    pattern7(7);
    std::cout<<std::endl;
    return 0;
}