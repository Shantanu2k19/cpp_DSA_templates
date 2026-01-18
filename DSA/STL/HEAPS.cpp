#include<bits/stdc++.h>
using namespace std;

//12 8 10 6 4 3 9 1 2 
void heapify(vector<int> &heap, int curInd, int size){
    int largest = curInd;
    int l = 2*curInd+1;
    int r = 2*curInd+2;

    if(l<size and heap[l]>heap[largest])
        largest=l;
    if(r<size and heap[r]>heap[largest])
        largest=r;
    if(largest!=curInd){
        int temp = heap[curInd];
        heap[curInd]=heap[largest];
        heap[largest]=temp;

        heapify(heap, largest, size);
    }
}


void buildHeap(vector<int>& heap){
    //build heap, rearrange array
    for(int i=heap.size()/2-1; i>=0; i--){
        //leaf nodes are already heapified, so do this for inner elements 
        heapify(heap,i,heap.size());
    }
}

void heapSort(vector<int>& heap){
    for(int i=heap.size()-1; i>0; i--){
        int temp = heap[0];
        heap[0]=heap[i];
        heap[i]=temp;

        heapify(heap,0,i);
    }
}

void heapPush(vector<int>& heap, int ele){
    int n = heap.size();

    heap.push_back(ele);
    int curInd = n;

    while(curInd>0 and heap[(curInd-1)/2]<heap[curInd]){
        int temp = heap[(curInd-1)/2];
        heap[(curInd-1)/2]=heap[curInd];
        heap[curInd]=temp;

        curInd = (curInd-1)/2;
    }
}

void heapPop(vector<int>&heap){
    int n = heap.size();

    if(n<0) return;

    int curInd = 0;
    int popped = heap[0];
    heap[0]=heap[n-1];

    while((2*curInd+1)<n){
        int child;
        if((2*curInd+2)>=n) //if we only have left child
            child = 2*curInd+1;
        else{
            //if both present, find max
            if(heap[2*curInd+1]>heap[2*curInd-1])
                child=2*curInd+1;
            else
                child=2*curInd+2;
        }

        //if curr node is lower than max(leftchil, rightchild), then swap and heapify
        if(heap[curInd]<heap[child]){
            int temp = heap[curInd];
            heap[curInd]=heap[child];
            heap[child]=temp;

            curInd=child;
        }
        else break;
    }
}

void showHeap(vector<int> &heap){
    for(auto x: heap){
        cout<<x<<", ";
    }
    cout<<endl;
}


int main(){
    vector<int> heap{ 9, 6, 10, 1, 4, 3, 12, 8, 2};
    buildHeap(heap);

    // heapSort(heap);
    showHeap(heap);

    heapPush(heap, 5);
    showHeap(heap);

    heapPop(heap);
    showHeap(heap);


    cout<<"\n_________________\n";
}