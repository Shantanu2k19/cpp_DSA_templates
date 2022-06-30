//duplicate key cannot be inserted in a map
#include<bits/stdc++.h>
using namespace std;


//         map<int, set<int>> posMap;
//         for (int i = 0; i < nums.size(); i++) {
//             int num = nums[i];
//             if (posMap[target - num].size() > 0) {
//                 // We can assume there is exactly one solution.
//                 return {i, *posMap[target - num].begin()};
//             }
//             // If not found insert current pos into the posMap.
//             posMap[num].insert(i);
//         }
//         return {};

int main(){
    map<int, int> lol;

    lol.insert(pair<int, int>(1,400));
    lol.insert({69,420});

    map<int, int>::iterator gg;
    for(gg=lol.begin(); gg!=lol.end(); gg++){  //auto gg=lol.begin()
        cout<<gg->first<<" "<<gg->second<<endl;
    }

    unordered_map<int, int> lol2(lol.begin(),lol.end());
    cout<<endl;

    //FINDING ELEMENT

    cout<<"at: "<<lol.at(69);
    if(lol.find(69)!=lol.end()){
        cout<<"\nfound"<<endl;
    }
    cout<<"count: "<<lol.count(77);  //0 or 1
    cout<<endl;

    //find also like this
    if(lol.count(69)==0) cout<<"69 not found";
    else cout<<"69 found";

    //INCREMENT VALUE IF KEY EXIST
    //ADD if does not exist 
    int arr[5] = {1,69,1,99,33};
    for(int i=0;i<5;i++){
        lol[arr[i]]++;
    }
    for(gg=lol.begin(); gg!=lol.end(); gg++){  //auto gg=lol.begin()
        cout<<gg->first<<" "<<gg->second<<endl;
    }


    //deletion
    //remove all elements up to element with key=2 in lol, 2 not included
    lol.erase(lol.begin(), lol.find(2));

    bool num = lol.erase(9);  //remove element with key=8, num=0/1, false/true
    cout<<endl<<num<<endl;


    // lower_bout : if found, points at element
    // not found : points at element larger than it 
    // else points to .end()
    cout<<"LB - ";
    auto kk = lol.lower_bound(200);
    cout<<(*kk).second;

    cout<<"\n_________________________________________\n";
}