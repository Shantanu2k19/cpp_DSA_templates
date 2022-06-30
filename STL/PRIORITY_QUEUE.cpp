#include<bits/stdc++.h>
using namespace std;

//for custom comparator
class compare{
    public:
    bool operator()(char a, char b){ //change to int for int
        return a>b;
    }
};

//insertion : logN
//deletion : logN
//max : o(1)

int main(){
    int arr[] = {10,15,20,30,50,19};
    int n = sizeof(arr)/sizeof(int);

    //by default it is a max heap 
    priority_queue<int> heap;
    // priority_queue<int, vector<int>, compare> minHeap;  //greater is a comparitor 
    priority_queue<int, vector<int>, greater<int> > minHeap;  //greater is a comparitor 
    
    for(int x:arr){
        heap.push(x);
        minHeap.push(x);
    }
    while(!heap.empty()){
        cout<<heap.top()<<" ";
        heap.pop();
    }

    cout<<endl;

    while(!minHeap.empty()){
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }

    char arr2[] = {'a', 'd', 'f', 'o', 'p', 'z'};
    priority_queue<char, vector<char>, compare> charHeap;
    for(auto i: arr2){
        charHeap.push(i);
    }
    cout<<endl;
    while(!charHeap.empty()){
        cout<<charHeap.top()<<" ";
        charHeap.pop();
    }

    cout<<"\n_____________________________\n";
}                                       

/*
for tree
parent = i
left child = 2i+1
right child = 2i+2

            1
      2          5
    3   4      6   7

val : 1 2 5 3 4 6 7
ind : 0 1 2 3 4 5 6

if 
child = i
parent = ceil(i/2)-1


for a perfect binary tree:
if height = h
max nodes at height h = 2^h
nodes in entire tree = 2^(h+1) -1

in a perfect binary tree, number of internal nodes = number of leaves -1

height of the tree for given number of node n = floor(log2N) base2

*/