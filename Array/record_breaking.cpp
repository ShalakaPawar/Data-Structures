#include<bits/stdc++.h>

//find the number of record breaking days in the array
//follow conditions
int solution(int array[], int size){
    int max_till_now = INT_MIN, record_days=0;
    for(int i=0; i<size; i++){
        //conditions
        if(array[i] > max_till_now && (i == size-1 || array[i+1] < array[i]))
            record_days++;
        max_till_now = std::max(array[i], max_till_now);
    }
    return record_days;
}

int main(){
    // 9, 2, 3, 4, 5, 6, 7, 8, 18, 0
    //0,5,4,6,8
    //1,2,0,7,
    //10,7,4,6,8,10,11
    int arr[] = {3,2,0,7,2,0,2,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sol = solution(arr, n);
    std::cout<<sol;
    return 0;
}