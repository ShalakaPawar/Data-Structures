#include<bits/stdc++.h>
using namespace std;

//which_case - upper 1 or lower 0
void changeCase(string str){
    for(int i=0; i<str.size(); i++){
        if('a' <= str[i] && str[i] <= 'z'){
            str[i] -= 32;
        }
        else if('A' <= str[i]  && str[i]<= 'Z'){
            str[i] += 32;
        }
    }
    cout<<str<<endl;
}

int main(){
    string str = "FaBDna  L";
    changeCase(str);
    //function for help
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout<<str;
    return 0;
}