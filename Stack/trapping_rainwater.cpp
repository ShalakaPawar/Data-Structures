#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;


// time-O(n)
int* prev_largest(int* array, int n){
    int* result = new int[n];
    int max = array[0];
    for(int i=0; i< n; i++){
        if(array[i] > max)
            max = array[i];
        result[i] = max;
    }
    return result;
}

// we need ultimate largest on the right side
int* next_largest(int* array, int n){
    reverse(array, array+n);
   int* result = new int[n];
    int max= array[0];
    for(int i=0; i< n; i++){
        if(array[i] > max)
            max = array[i];
        result[n-1-i] = max;
    }
    reverse(array, array+n);
    return result;
}

int trapping_rainwater(int* array, int n){
     // find the smallest on left
    int* prev = prev_largest(array, n); //O(n)
    // find the largest on the right
    int* next = next_largest(array, n); //O(n)
    int waterBlocks = 0;
    for (size_t i = 0; i < n; i++)
    {
        int w = min(next[i],prev[i]) - array[i];
        waterBlocks+=w;
    }
    return waterBlocks;
}

int main(){
//{3,1,2,4,0,1,3,2};
  int arr[] ={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
      
   
    cout<<endl;
    cout<<"\nRainwater trapped = "<<trapping_rainwater(arr, n);
    return 0;
}