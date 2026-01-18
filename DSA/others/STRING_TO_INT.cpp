#include<bits/stdc++.h>
using namespace std;

int main(){

    //STRING TO INT
    float a;
    string str="123.43&%following doesn't matter lol 1244";
    a = stoi(str);
    cout<<a<<endl;

    string str2="123.43&%following doesn't matter lol 1244";
    stringstream number(str2);
    float x=0;
    number>>x;
    cout<<x<<endl;


    //INT TO STRING
    int n=25;
    string s = std::to_string(n);
    cout<<s<<endl;

    ostringstream obj;
    obj << n;
    string lol = obj.str();
    cout<<lol+" string"<<endl;


    cout<<"\n_____________________________\n";
}                                       