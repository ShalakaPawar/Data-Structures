// nxn maze
//0,0 --> n-1, n-1
#include<bits/stdc++.h>
using namespace std;
int solution(int n, int i, int j){
    //base case
    if(i==n-1 && j==n-1)
        return 1;
    if(i>=n || j>=n)
        return 0;
    return solution(n, i, j+1) + solution(n, i+1, j);
}

int main(){
    cout<<solution(3, 0,0);
    return 0;
}