//board game
//with dice - 1 to 6
#include<bits/stdc++.h>
using namespace std;
int solution(int start, int end){
    //base case
    if(start == end)
        return 1;
    if(start > end)
        return 0;
    int count=0;
    for(int i=1; i<6; i++){
        count+=solution(start+i, end);
    }
   return count;
}

int main(){
    cout<<solution(1, 4);
    return 0;
}