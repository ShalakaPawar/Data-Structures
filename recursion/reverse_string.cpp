#include<bits/stdc++.h>
using namespace std;

//reverse string using recursion

//void reverse(int array[], int start, int end){
void reverse(string str, int start, int end){
    if(start>end)
        return;
    reverse(str, start+1, end);
    cout<<str[start]<<endl;
}
int main(){
    int a[] = {4,2,1,2,5,2,7};
    string str="varun";
    int n = sizeof(a)/sizeof(a[0]);
    reverse(str, 0, str.size()-1);
    return 0;
}