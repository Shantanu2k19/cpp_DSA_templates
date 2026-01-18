#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={4,2,5,7,3,5,7,8,4,2,5,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]<arr[j]){
                int temp=0;
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<"\n_____________________________\n";
}                                       