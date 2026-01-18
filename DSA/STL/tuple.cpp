#include<bits/stdc++.h>
#include<tuple>
using namespace std;
int main(){
    tuple<char, int, float> tup;

    tup = make_tuple('s', 100, 69.420);

    cout<<get<0>(tup)<<",";
    cout<<get<1>(tup)<<",";
    cout<<get<2>(tup)<<endl;

    //update
    get<1>(tup)=20;
    cout<<get<1>(tup)<<"\n";

    //no of elements in tuple
    cout<<"size: "<<tuple_size<decltype(tup)>::value<<endl;

    //swap values of tuple
    tuple<char, int, float> tup2('b',40, 0.02);

    tup.swap(tup2);
    cout<<"after swapping : \n";
    cout<<get<0>(tup)<<",";
    cout<<get<1>(tup)<<",";
    cout<<get<2>(tup)<<endl;

    //unpacking
    int a;
    char c;
    float f;

    tuple<int,char,float> tup3(1,'a',0.1);
    tie(a,c,f)=tup3;
    cout<<"\nafter tie : \n";
    cout<<a<<","<<c<<","<<f<<endl;

    //if don't want all values 
    //tie(a,ignore,f)=tup3;

    // int kk = get<0>(tup3);
    // cout<<kk;  //also works


    //concatinate tuple
    // auto tup4 = tuple_cat(tup2,tup3);
    tuple<char,int,float,int,char,float> tup4 = tuple_cat(tup2,tup3);

    cout<<"\nafter concatination\n";
    cout<<get<0>(tup4)<<",";
    cout<<get<1>(tup4)<<",";
    cout<<get<2>(tup4)<<",";
    cout<<get<3>(tup4)<<",";
    cout<<get<4>(tup4)<<",";
    cout<<get<5>(tup4)<<"\n";




    cout<<"\n_________________\n";
}