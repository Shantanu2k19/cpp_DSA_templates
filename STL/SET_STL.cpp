//set : value cannot be modified, tho deleted 
//no repeated values 
#include<iostream>
#include<set>
using namespace std;

//MULTISET FOR MORE THAN ONE VALUES

int main(){
    set<int> lol;
    lol.insert(1);
    lol.insert(69);
    lol.insert(420);

    //for decreasing order 
    set<int, greater<int> > lol2(lol.begin(), lol.end());
    
    //420 not included
    lol.erase(lol.begin(),lol.find(420));
    if(lol.find(420)!=lol.end()){
        cout<<"\n420 found \nafter deletion: ";
    }

    // unordered_set<int> lol2;
    for(auto itr:lol){
        cout<<itr<<" ";
    }
    cout<<"\n\n";

    for(auto itr: lol2){
        cout<<itr<<" ";
    }

    cout << "\nlol.lower_bound(60) : \n"
         << *lol.lower_bound(60)
         << endl;
    //looks same as upper bound 

    //greater than value, if none returns size of
    cout << "lol.upper_bound(60) : \n"
         << *lol.upper_bound(60)
         << endl;
    
    cout<<"\n______________________\n";
}