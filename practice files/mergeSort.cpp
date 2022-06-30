#include <bits/stdc++.h>
using namespace std;

void waterHarvest(int arr[], int l){
    int left[l];
    int right[l];
    int maxx=0;

    //left max
    for(int i=0;i<l;i++){
        maxx = max(arr[i],maxx);
        left[i] = maxx;
    }

    //right max 
    maxx = 0;
    for(int i=l;i>=0;i--){
        maxx = max(arr[i],maxx);
        right[i] = maxx;

    }

    int water = 0;
    for(int i=0;i<l;i++){
        //cout<<arr[i]<<" "<<left[i]<<" "<<right[i]<<endl;
        water += (min(left[i],right[i])-arr[i]);
        //cout<<water<<endl;
    }
    cout<<water;
}

int main() {
    int arr[]={4,2,0,3,2,5};
    int l=sizeof(arr)/sizeof(arr[0]);
    //waterHarvest(arr,l-1);
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    cout<<a.size();
    cout<<"\n________________\n";
}







//resource:///org/gnome/shell/theme/noise-texture.png