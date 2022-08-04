#include<bits/stdc++.h>
using namespace std;
/*
stack<int> createStack(vector<int>v){
    stack<int> s;
    for(auto h : v){
        if(s.empty())
            s.push(h);
        else
            s.push(h + s.top());
    }
    return s;
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    stack<int> s1, s2, s3;
    s1 = createStack(h1);
    s2 = createStack(h2);
    s3 = createStack(h3);
    while(!s1.empty() && !s2.empty() && !s3.empty()){
        if(s1.top() == s2.top() && s2.top() == s3.top())
            break;
        if(s1.top() > s2.top() && s1.top() > s3.top())
            s1.pop();
        else if(s2.top() > s1.top() && s2.top() > s3.top())
            s2.pop();
        else if(s3.top() > s1.top() && s3.top() > s2.top())
            s3.pop();
    }
    if(s1.empty() || s2.empty() || s3.empty())
        return 0;
    return s1.top();
}
*/


stack<int> createStack(vector<int>v, int &sum){
    stack<int> s;
    sum = 0;
    for(int h = v.size()-1; h >= 0; h--){
        s.push(v[h]);
        sum += v[h];
    }
    return s;
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    int height1{0}, height2{0}, height3{0};
    stack<int> s1, s2, s3;
    s1 = createStack(h1, height1);
    s2 = createStack(h2, height2);
    s3 = createStack(h3, height3);
    while(!s1.empty() && !s2.empty() && !s3.empty()){
        if(s1.top() == s2.top() && s2.top() == s3.top())
            break;
        if(s1.top() > s2.top() && s1.top() > s3.top())
            s1.pop();
        else if(s2.top() > s1.top() && s2.top() > s3.top())
            s2.pop();
        else if(s3.top() > s1.top() && s3.top() > s2.top())
            s3.pop();
    }
    if(s1.empty() || s2.empty() || s3.empty())
        return 0;
    return s1.top();
}

int main(){
    vector <int> v1 = {3, 2, 1, 1, 1};
    int a = equalStacks({3, 2, 1, 1, 1},{4, 3, 2},{1, 1, 4, 1});
    cout<<a<<endl;

    return 0;
}