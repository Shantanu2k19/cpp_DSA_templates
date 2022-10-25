#include<bits/stdc++.h>
using namespace std;

int main(){
    bitset<8> b1(string("111")); //initalized with bits of 10
    bitset<8> b2(10);

    cout<<b1<<endl<<b2<<endl;

    b2[0]=1;
    cout<<b2<<endl;

    //COUNT - no of setbits
    cout<<"count:"<<b1.count()<<endl;

    //SIZE - total no of bits 
    cout<<"size:"<<b1.size()<<endl; 

    //TEST - return if bit is set
    cout<<"0 index : "<<b1.test(0)<<endl;

    //ANY - return if atleast 1 bit is set
    //b1.any()

    //NONE - returns if none is set
    //b1.none()

    //SET - sets all bits 
    //b1.set()
    //b1.set(pos, bit)
    //b1.set(pos) //makes pos 1 (default)

    //RESET - makes all bits 0
    cout<<b1.reset()<<endl;
    //b1.reser(pos);

    //FLIP - flips all bit
    //b1.flip();
    //b1.flip(pos);



    //CONVERT decimal number to BINARY
    int num = 100;
    cout<<endl<<num<<"->"<<bitset<8>(num);


    cout<<"\nOPRATIONS\n\n";

    bitset<8> a(3);
    bitset<8> b(5);

    cout<<"a:"<<a<<"\nb:"<<b<<endl;

    cout<<(a^b)<<endl;
    cout<<(a&b)<<endl;
    cout<<(a<<2)<<endl;
    cout<<(~a)<<endl;



    cout<<"\n_________________\n";
}