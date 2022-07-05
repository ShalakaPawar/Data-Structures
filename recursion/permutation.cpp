#include<bits/stdc++.h>
using namespace std;
void solution(string s, string ans){
    //base case
    if(s.length() == 0){
        cout<<ans<<endl;
        return;
    }

    for(int i=0; i<s.length(); i++){
        char c=s[i];
        string ros = s.substr(0, i) + s.substr(i+1);
        solution(ros, ans+c);
    }
}

int main(){
    string s = "ABC";
    solution(s, "");
    return 0;
}