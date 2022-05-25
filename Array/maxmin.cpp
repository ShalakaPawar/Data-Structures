#include<iostream>

class minmax{
public:
    int max = 0;
    int min = 0;
};

minmax getminmax(int array[], int size){
    minmax mm = minmax();
    mm.max = mm.min = array[0];
    for(int i=1; i< size; i++){
        if (array[i] < mm.min)
            mm.min = array[i];
        else if (array[i] > mm.max)
            mm.max = array[i];
    }
    return mm;
}

minmax solve(int array[], int size){
    minmax mm = minmax();
    int i=0;
    // even
    if (size%2 == 0){
        if (array[0] < array[1]){
            mm.min = array[0];
            mm.max = array[1];
        }
        else{
            mm.max = array[0];
            mm.min = array[1];
        } 
        i = 2;
    }
    else{
        //odd
        mm.max = mm.min = array[0];
        i = 1;
    }
    for(i; i< size; i+=2){
        int smaller, larger;
        if (array[i] < array[i+1]){
            larger = array[i+1];
            smaller = array[i];
        }
        else{
            larger = array[i];
            smaller = array[i+1];
        }
        if (mm.max < larger)
            mm.max = larger;
        if (mm.min > smaller)
            mm.min= smaller;
    }
    return mm;
}

int main(){
    int array[] = {111,2,32,40,5,6};
    //minmax m = getminmax(array, 6);
    minmax m = solve(array, 6);

    std::cout<<m.max<<"\n"<<m.min;
    return 0;
}