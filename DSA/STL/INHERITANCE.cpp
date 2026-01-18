#include <bits/stdc++.h>
using namespace std;

//Base class
class Parent{
    private:
    string name="shan";
	public:
	int id_p=2;
    protected:
    int age=20;

    public:
    void lol(){
        cout<<"parent\n";
        cout<<name<<endl;
        cout<<id_p<<endl;
        cout<<age<<endl;
    }
};

class Child : public Parent{
	public:
	void lol2(){
        cout<<"chile\n";

        cout<<id_p<<endl;
        cout<<age<<endl;
    }
};

class Grandchild : public Child{
    public: 
    void lol2(){
        cout<<"gc\n";

        cout<<id_p<<endl;
        cout<<age<<endl;
    };
};

//main function
int main(){
		// Child obj1;
        Parent p;
        p.lol();
        // obj1.lol2();
        // Grandchild g;
        // g.lol2();
		// obj1.id_c = 7;
		// obj1.id_p = 91;
        // obj1.age = 23;
		// cout << "Child id is " << obj1.id_c << endl;
		// cout << "Parent id is " << obj1.id_p << endl;
		
        cout<<"\n______________________\n";
		return 0;
}
