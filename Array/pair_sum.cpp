#include<bits/stdc++.h>

//O(n^2) approach
bool pairSumOne(int array[], int size, int sum){
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if(array[i]+array[j] == sum)
                return true;
        }
    }
    return false;
}

// sort the elements and use two pointers
bool pairSumTwo(int array[], int size, int sum){
    //mergesort - O(nlogn)
    std::sort(array, array+size);
    int low=0, high = size-1;
    for(int i=0;i<size;i++){
        if(sum - array[i] < 0){

        }
    }
}

int main(){
    
    return 0;
}