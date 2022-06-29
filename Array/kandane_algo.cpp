#include<bits/stdc++.h>
using namespace std;
int maxSubArraySum(int array[], int size){
    int curr_sum=0, max_val=0;
    for(int i=0; i<size; i++){
        if(curr_sum < 0){
            curr_sum = 0;
        }
        curr_sum += array[i];
        if(curr_sum > max_val)
            max_val = curr_sum;
    }
    return max_val;
}

int main()
{
    int a[] = {-2, -3, 6, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}