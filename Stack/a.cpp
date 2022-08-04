#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v = {5,3,6};
    stack<int> s;
    int sum=0;
     for(int h = v.size()-1; h >= 0; h--){
        s.push(v[h]);
        cout<<v[h];
        sum += v[h];
    }

}