#include<bits/stdc++.h>
using namespace std;

bool isSafe(int** arr, int n, int x, int y){
    //safe in row
    int row, col;
    for(row=0; row<n;row++){
        if(arr[row][y] == 1)
            return false;
    }

    //safe diagonally
    row = x;
    col = y;
    //left diagonal
    while(row>=0 && col>=0){
        if(arr[row][col] == 1)
            return false;
        row--;
        col--;
    }
    row = x;
    col = y;
    //right diagonal
    while(row>=0 && col<n){
        if(arr[row][col] == 1)
            return false;
        row--;
        col++;
    }
    return true;
}

// iterate through the columns
bool nqueen(int** arr, int n, int x){
    if(x>=n){
        return true;
    }
    for(int col=0;col<n;col++){
        if(isSafe(arr, n, x, col)){
            arr[x][col] = 1;
            if(nqueen(arr, n, x+1)){
                return true;
            }
            arr[x][col] = 0;    //backtracking
        }
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
   int** array = new int*[n];
   for(int i=0; i<n;i++){
        array[i] = new int[n];
        for(int j=0;j<n;j++){
            array[i][j] = 0;
        }
   }
    if(nqueen(array, n, 0))
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<array[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
}