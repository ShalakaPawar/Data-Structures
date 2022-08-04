#include<iostream>
#include<vector>
using namespace std;

int max_consec(vector<int> array){
    int count = 1, max = 1;
    for(int i=1; i< array.size(); i++){
        if(array[i] = 1){
            count++;
        }
        else{
            count = 0;
        }
        if(count > max)
                max = count;
    }
    return max;
}

int main(){
     vector<int> price ={0,0,1,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int soln = max_consec(price);
    cout<<soln<<endl;
    return 0;
}