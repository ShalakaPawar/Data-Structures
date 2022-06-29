#include<bits/stdc++.h>
using namespace std;
void solution(int n){
    if(n==0)
        return;
    cout<<n<<endl;
    solution(n-1);
}
int main(){
    solution(5);
    return 0;
}