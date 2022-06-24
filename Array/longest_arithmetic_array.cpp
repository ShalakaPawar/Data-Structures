#include<bits/stdc++.h>

//logest arithmetic sub array
//return length
int solution(int array[], int size){
    int max_len = 0, prev_diff = 0, curr_diff = 0, curr_len = 0;
    if (size < 2)
        return 0;
    prev_diff = array[0] - array[1];
    for(int i=0;i<size-1; i++){
        curr_diff = array[i]-array[i+1];
        if (prev_diff == curr_diff){
            curr_len += 1;
        }else{
            if(max_len < curr_len)
                max_len = curr_len;
            curr_len = 1;
        }
        prev_diff = curr_diff;
    }
    return max_len+1;
}

int main(){
    // 9, 2, 3, 4, 5, 6, 7, 8, 18, 0
    //0,5,4,6,8
    //1,2,0,7,
    int arr[] = {10,7,4,6,8,10,11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sol = solution(arr, n);
    std::cout<<sol;
    return 0;
}