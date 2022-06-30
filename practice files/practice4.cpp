#include<iostream>
using namespace std;

void EE(int m){
    try {
        if(m)
        throw m*=2;
    }
    catch(int a){
        cout<<"C"<<a<<" ";
    }
}

int main(){
    EE(1);
    EE(3);
    EE(5);
    return 0;

}
//2 6 10