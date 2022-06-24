#include<bits/stdc++.h>

void sum_of_subarrays(int arr[], int size){
    int* sum_sarray = new int[100];
    int index=0;
    for (int i=0; i<size; i++){
        int val=0;
        for (int j=i; j<size; j++){
            val += arr[j];
            sum_sarray[index++] = val;
        }
    }
    for(int i=0; i<index; i++)
        std::cout<<sum_sarray[i]<<"\t";
}
int main(){
    // 9, 2, 3, 4, 5, 6, 7, 8, 18, 0
    //0,5,4,6,8
    int arr[] = {1, 2,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    sum_of_subarrays(arr, n);
    
    return 0;
}