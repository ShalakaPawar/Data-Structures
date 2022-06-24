#include<bits/stdc++.h>

// find the 1st repeating element - lowest index 
//returns -1 for no repeating element
int solution(int array[], int size){
    int* new_arr = new int[size+1];
    for(int i=0; i<size+1; i++)
        new_arr[i] = -1;
    int count=0, minIndex = INT_MAX;
    for(int i=0; i<size; i++){
        int val = array[i];
        //not repeated yet
        if (new_arr[val] == -1){
            new_arr[val] = count++;
        }
        else{
            if(new_arr[val] < minIndex)
                minIndex = new_arr[val];
        }
    }
    return minIndex+1;
} 

int main(){
    // 9, 2, 3, 4, 5, 6, 7, 8, 18, 0
    //0,5,4,6,8
    //1,2,0,7,
    int arr[] = {1,5,3,4,3,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sol = solution(arr, n);
    std::cout<<sol;
    return 0;
}