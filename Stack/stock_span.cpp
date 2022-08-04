#include<iostream>
#include<stack>
using namespace std;

int* stock_span(int* array, int n){
    stack<int> stk;
    int* result = new int[n];
    for(int i=0; i< n; i++){
        while(!stk.empty() && array[stk.top()] < array[i]){
            stk.pop();
        }
        if(stk.empty() == true){
            // current element is largest till now
            result[i] = i+1;
        }
        else
            result[i] = i - stk.top();
        stk.push(i);
    }
    return result;
}
   
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 

int main(){
     //int price[] = { 10, 4, 5, 90, 120, 80 };
     int price[] ={100,80,60,70,60,75,85};
    int n = sizeof(price) / sizeof(price[0]);
    int* soln = stock_span(price, n);
    printArray(soln, n);
    return 0;
}