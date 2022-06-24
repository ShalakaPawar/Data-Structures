#include<iostream>
#include<algorithm>
using namespace std;

// time - O(n), size - O(n)
int* max_till_i(int arr[], int size){
    int* new_arr, max_val{INT_MIN};
    new_arr =  new int[size];
    for (int i=0; i<size; i++){
        max_val = max(arr[i], max_val);
        new_arr[i] = max_val;
    } 
    return new_arr;
}

int main()
{
    // 9, 2, 3, 4, 5, 6, 7, 8, 18, 0
    int arr[] = {1,0,5,4,6,8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int* max_array = max_till_i(arr, n);
    for(int i=0; i<n; i++)
        cout<<max_array[i]<<"\t";
    return 0;
}