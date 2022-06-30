#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> lol{1,6,7,8,99};

    int s=0, e=lol.size()-1;
    int ele = 80;
    while(s<e){
        int mid=s+(e-s)/2;

        if(ele<=lol[mid]) e=mid;
        else s=mid+1;
    }
    if(s<lol.size() && lol[s]<ele) s++;

    vector<int>::iterator lower = lower_bound(lol.begin(), lol.end(), ele);
    cout<<s<<endl;
    cout<<lower-lol.begin()<<endl;



    cout<<"\n_____________________________\n";
}                                       