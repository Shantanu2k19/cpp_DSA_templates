#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int s, int e){
    int pivot=arr[e];
    int i=s-1;
    for(int j=s;j<e;j++){
        if(arr[j]<pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[e];
    arr[e]=temp;
    return i+1;
}

void quickSort(vector<int> &arr, int s, int e){
    if(s>=e) return;

    int p = partition(arr,s,e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main(){
    vector<int> arr{4,2,5,7,3,5,7,8,4,2,5,8};
    int n = arr.size()-1;

    quickSort(arr, 0, n);
    for(auto itr: arr){
        cout<<itr<<" ";
    }
    cout<<"\n_____________________________\n";
}                                       