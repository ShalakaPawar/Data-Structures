#include<bits/stdc++.h>
using namespace std;
void solution(int array[], int start, int end, int num){
    if(start>end)
        return;
    if(array[start] == num && array[end] == num){
        cout<<"first="<<start<<"\nlast="<<end<<endl;
        return;
    }
    if(array[start] != num)
        solution(array, start+1,end, num);
    else if(array[end] != num)
        solution(array, start,end-1, 2);
}
int main(){
    int a[] = {4,2,1,2,5,2,7};
    int n = sizeof(a)/sizeof(a[0]);
    solution(a, 0,n-1, 4);
    return 0;
}