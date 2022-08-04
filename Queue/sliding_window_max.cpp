#include<iostream>
#include<deque>
#include<vector>
using namespace std;

// n= size of array
// k = window size
vector<int>* sliding_win(int* array, int n, int k){
    vector<int>* res = new vector<int>;
    deque<int> dq;
    int i;
    // handle the first k elements
    for(i=0; i<k; i++){
        while(dq.empty() == false && array[dq.back()] <= array[i]){
            // deque contains element smaller then current element
            // pop it
            dq.pop_back();
        }
        // now useless elements have been removed
        dq.push_back(i);
    }
    // 1st window is over - element at front islargest
    res->push_back(array[dq.front()]);

    //do similar for all elements
    for(; i<n; i++){
        //window is sliding - remove out of window elements
        // check index less than window size
        while(dq.empty() == false && dq.front() < i-k+1){
            dq.pop_front();
        }

        while(dq.empty() == false && array[dq.back()] <= array[i]){
            // deque contains element smaller then current element
            // pop it
            dq.pop_back();
        }
        // now useless elements have been removed
        dq.push_back(i);
        res->push_back(array[dq.front()]);
    }
    //res->push_back(array[dq.front()]);
    return res;
} 

int main(){
   //  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int  arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, k = 4; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  //  int k = 3; 
    vector<int>* res = sliding_win(arr, n, k);
    cout<<"\nResult: ";
    for(int i : *res){
        cout<<i<<"\t";
    }
    return 0;
}