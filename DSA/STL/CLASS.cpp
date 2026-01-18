#include<bits/stdc++.h>
using namespace std;

class automobile{
    string name;
    public:
        int price;
        string fuel;
};

class car: public automobile{ //access mode, base class
    public:
    int number;
};

int main(){
    automobile veh;
    // veh.name = "tesla"; //name is inaccessible since it's private
    veh.price = 420;
    veh.fuel = "electric";

    car cc;
    cc.number = 69;
    cc.fuel = "gas";
    
    cout<<"\n_____________________________\n";
}                                       