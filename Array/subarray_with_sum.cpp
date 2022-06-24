#include<bits/stdc++.h>

// subarray with given sum
int* solution(int array[], int size, int sum){
    int value=0;
    int* result = new int[2];  //2 values - start index, end index
    for(int i=0; i<size; i++){
        value=0;
        for(int j=i; j<size; j++){
            value += array[j];
            if(value==sum){
                result[0] = i+1;
                result[1] = j+1;
                return result;
            }
        }
    }
    return NULL;
}

int main(){
    // 9, 2, 3, 4, 5, 6, 7, 8, 18, 0
    //0,5,4,6,8
    //1,2,0,7,
    int arr[] = {1,2,3,7,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int* sol = solution(arr, n, 12);
    std::cout<<sol[0]<<" "<<sol[1];
    return 0;
}