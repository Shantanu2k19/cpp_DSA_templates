#include<iostream>
using namespace std;

struct lol{
    int kk=0;
    string pp="lmao";
};

int main(){
    struct lol obj;
    //struct lol obj = {420,'gg'};
    //initialize if not initialized in structure 
    obj.kk = 69;
    cout<<obj.pp<<" "<<obj.kk;

    cout<<endl;
    //structure pointer 
    //pnt is a pointer to structure obj
    struct lol* pnt = &obj;
    cout<<pnt->kk<<" "<<pnt->pp;

    

    cout<<"\n____________________\n";
}