#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//greater<int>
//less_equal<int>

int main(){
    pbds a;
    a.insert(1);
    a.insert(10);
    a.insert(30);
    a.insert(5);

    for(auto x: a){
        cout<<x<<",";
    }
    cout<<endl;


    //finding kth element
    cout<<"1st index :"<<*a.find_by_order(1)<<endl;

    //find no of element smaller than x
    cout<<"no of elements smaller than 10 :"<<a.order_of_key(10)<<endl;

    //lower bound : first element >= x
    cout<<"lower bound 10: "<<*a.lower_bound(10)<<endl;

    //uper bound : first ele > x
    cout<<"uppder bound 10: "<<*a.upper_bound(10)<<endl;

    //delete element
    a.erase(10);

    for(auto x: a){
        cout<<x<<",";
    }

    cout<<"\n_________________\n";
}