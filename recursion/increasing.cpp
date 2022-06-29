#include<bits/stdc++.h>
using namespace std;

bool is_increasing(int array[], int start, int end){
  
    if(start==end || (array[start]<=array[start+1] && is_increasing(array, start+1, end)))
        return true;
    return false;
}

int main(){
    int a[] = {1, 3, 5, 9, 53};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<is_increasing(a, 0, n-1);
}