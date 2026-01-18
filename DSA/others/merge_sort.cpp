#include<bits/stdc++.h>
using namespace std;

void mergeArray(vector<int> &arr, int s, int e){
    int mid = (s+e)/2;

    int i=s,j=mid+1;
    vector<int> temp;

    while(i<=mid && j<=e){
        if(arr[i]<arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid) temp.push_back(arr[i++]);
    while(j<=e) temp.push_back(arr[j++]);

    int ind=0;
    for(int k=s;k<=e;k++) arr[k]=temp[ind++];
    return;
}

void mergeSort(vector<int> &arr, int s, int e){
    if(s>=e) return;

    int mid = (s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    mergeArray(arr, s, e);
}

int main(){
    vector<int> arr{4,2,5,7,3,5,7,8,4,2,5,8};
    int n = arr.size()-1;

    mergeSort(arr,0, n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<"\n_____________________________\n";
}                                       