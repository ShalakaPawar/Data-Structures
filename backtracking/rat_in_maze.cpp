#include<bits/stdc++.h>
using namespace std;

bool isSafe(int** arr, int n, int x, int y){
    if(x < n && y < n && arr[x][y] == 1){
        return true;
    }
    return false;
}

bool rat_in_maze(int** arr, int n, int x, int y, int** solArr){
    //base case
    if(x == n-1 && y == n-1){
        solArr[x][y] = 1;
        return true;
    }
    if(isSafe(arr, n, x, y)){
        solArr[x][y] = 1;
        if(rat_in_maze(arr, n, x+1, y, solArr) || rat_in_maze(arr, n, x, y+1, solArr)){
            return true;
        }
        //backtracking step
        solArr[x][y] = 0;
        return false;
    }
    return false;
}

int main(){
    int n=5;
   // int array[n][n] = [[
    // 1 0 1 0 1
    // 1 1 1 1 1
    // 0 1 0 1 0
    // 1 0 0 1 1
    // 1 1 1 0 1

   int** array = new int*[n];
   for(int i=0; i<n;i++){
        array[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>array[i][j];
        }
   }
    int **result_path = new int*[n];
    for(int i=0;i<n;i++){
        result_path[i] = new int[n];
        for(int j=0;j<n;j++){
            result_path[i][j]=0;
        }
    }
    cout<<"\nRat's output maze:\n";
    if(rat_in_maze(array, n, 0, 0, result_path)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<result_path[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}