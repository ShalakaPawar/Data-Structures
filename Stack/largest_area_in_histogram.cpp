// find the largest rectangular area in a histogram
#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

// time-O(n)
int* previous_smaller(int* array, int n){
    int* result = new int[n];
    stack<int> stk; 
    for(int i=0; i< n; i++){
        // if smaller exists in stack then add to result
        // and push current element
        // if element is larger then pop it
        while(!stk.empty() && array[stk.top()] >= array[i])
            stk.pop();
        if(stk.empty())
            result[i] = -1;
        else
            result[i] = stk.top();
        stk.push(i);
    }
    return result;
}

int* next_smaller(int* array, int n){
    reverse(array, array+n);
   int* result = new int[n];
    stack<int> stk; 
    for(int i=0; i< n; i++){
        // if smaller exists in stack then add to result
        // and push current element
        // if element is larger then pop it
        while(!stk.empty() && array[stk.top()] >= array[i])
            stk.pop();
        if(stk.empty())
            result[n-i-1] = n;
        else
            result[n-i-1] = n-stk.top()-1;
        
        stk.push(array[i]);
    }
    reverse(array, array+n);
    return result;
}

// time - O(n) O(1)
// int array - heights, width of all = 1
int largest_area(int* array, int n){
    // find the previous smaller
    int* prev = previous_smaller(array, n); //O(n)
    // find the next smaller
    int* next = next_smaller(array, n); //O(n)
    int max_area = -1;
    // o(n)
    for(int i=0; i<n; i++){
        int area = (next[i]-prev[i]-1)*array[i];
        if(area >max_area)
            max_area = area;
    }
    return max_area;
}

int main(){
     int  arr[] = {4,10,5,8,20,15,3,12}; 
    // int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]); 

    cout<<"Largest area = "<<largest_area(arr, n);
    return 0;
}