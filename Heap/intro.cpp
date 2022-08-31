#include<iostream>
#include<queue>
using namespace std;

#define SIZE 100

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
    return;
}
class heap{
public:
    int* harray;
    int capacity, size;

    heap(){
        harray = new int[SIZE];
        size = -1;
        capacity = SIZE;
    }

    void insert(int k){
        harray[++size] = k;
        int index = size;
        while(index >= 1){
            int parent = (index-1)/2;
            if(harray[parent] < harray[index]){
                swap(harray[parent], harray[index]);
                index = parent;
            }
            else
                break;
        }
        return;
    }

    void deletefromheap(){
        if(size==-1)
            return;
        harray[0] = harray[size];
        size--;

        //balance
        int currIndex=0;
        while(currIndex >= 0 && currIndex <=size){
            int leftIndex = 2*currIndex+1;
            int rightIndex = 2*currIndex+2;

            if(leftIndex <= size && harray[leftIndex] > harray[currIndex]){
                swap(harray[leftIndex], harray[currIndex]);
                currIndex = leftIndex;
            }
            else if(rightIndex <= size && harray[rightIndex] > harray[currIndex]){
                swap(harray[rightIndex], harray[currIndex]);
                currIndex = rightIndex;
            }
            else 
                return;
        }
    }

    void print(){
        cout<<"\nHeap formed: ";
        if(size == -1)
            return;
        for(int i=0; i<=size; i++){
            cout<<harray[i]<<"\t";
        }
        return;
    }
};

// creates heap from given array
void heapify(int* harray, int size, int currIndex){
    int largest = currIndex;
    int leftIndex = 2*currIndex+1;
    int rightIndex = 2*currIndex+2;
    if(leftIndex < size && harray[leftIndex] > harray[largest]){
        largest = leftIndex;
    }
    if(rightIndex < size && harray[rightIndex] > harray[largest]){
        largest = rightIndex;
    }
    if(largest != currIndex){
        swap(harray[largest], harray[currIndex]);
        heapify(harray, size, largest);
    }
    return;
}

void heapSort(int* harray, int size){
    int index = size;
    while(index > 0){
        swap(harray[0], harray[index-1]);
        index--;
        heapify(harray, index, 0);
    }
}

int main(){
    // define class
    heap *h = new heap();

    //insertion
    h->insert(50);
    h->insert(55);
    h->insert(53);
    h->insert(52);
    h->insert(54);
    h->print();

    // deletion
    h->deletefromheap();
    h->deletefromheap();
    h->print();

    // heapify function - gives the correct position to element 
    int arr[] = {54,53,55,52,50};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=size/2; i>=0; i--){
        heapify(arr, size, i);
    }
    cout<<"\nHeap = ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"\t";
    }

    // Heap Sort
    heapSort(arr, size);
    cout<<"\nHeap sort array = ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"\t";
    }

    // max heap - using std library
    priority_queue<int> pq;
    cout<<endl;
    if(pq.empty()){
        cout<<"heap is empty";
    }
    else
        cout<<"Heap is not empty";
    pq.push(1);
    pq.push(5);
    pq.push(4);
    pq.push(2);

    cout<<"\nTop element = "<<pq.top()<<endl;
    pq.pop();
    cout<<"\nTop element = "<<pq.top()<<endl;
    pq.pop();

    cout<<"Size = "<<pq.size()<<endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> pq_minheap;
    pq_minheap.push(1);
    pq_minheap.push(5);
    pq_minheap.push(4);
    pq_minheap.push(2);

    cout<<"\nTop element = "<<pq_minheap.top()<<endl;
    pq_minheap.pop();
    cout<<"\nTop element = "<<pq_minheap.top()<<endl;
    pq_minheap.pop();

    cout<<"Size = "<<pq_minheap.size()<<endl;
    return 0;
}