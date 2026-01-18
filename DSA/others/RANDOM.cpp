#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
    // cout<<time(0)<<endl;
    cout<<rand(); //value between 0 and rand_max
    cout<<"\n";

    // Use current time as seed for random generator
    srand(time(0));
    cout<<rand();

    cout<<"\n";
    cout<<rand()%21 +2000;  //random no between 2000-2021

    cout<<"\n_________________________\n";
}  