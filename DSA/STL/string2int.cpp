#include<bits/stdc++.h>
using namespace std;

int main(){
    //method 1
    string s = "123";
    cout<<stoi(s)+1;

    //method 2
    cout<<endl;
    stringstream temp(s);
    int y = 0;
    temp >> y;
    cout<<y+1;

    cout<<"\n_____________________________\n";
}                                       