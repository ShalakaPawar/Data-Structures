#include<iostream>
void reverse1(int* array, int start, int end){
    for(int i = 0; i<=(end-start)/2; i++){
        int temp = array[start + i];
        array[start+i] = array[end-i];
        array[end-i] = temp;
    }
    return;
}

void reverse2(int* arr, int start, int end){
    if (start >= end)
        return;
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverse2(arr, start+1, end-1);
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int size = 6;
    reverse1(arr, 0, size-1);
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}