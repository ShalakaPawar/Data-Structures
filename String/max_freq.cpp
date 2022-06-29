#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "dabcbaededddec";
    
    int characters[26] = {0};
    int max=0;
    for(int i=0; i<str.size(); i++){
        characters[str[i]-'a']++;
        if(max < characters[str[i]-'a'])
            max = characters[str[i]-'a'];
    }
    cout<<max<<endl;
    return 0;
}