#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void print_list(list<int> lol);

int main(){
    list<int> lol;

    lol.push_back(5);
    lol.push_back(6);
    lol.push_back(7);
    lol.push_front(3);

    print_list(lol);

    cout<<endl;
    cout<<lol.front()<<" "<<lol.back();

    lol.reverse();  //lol.sort();
    print_list(lol);

    //DELETION
    lol.pop_back();
    print_list(lol);

    list<int>::iterator itr1, itr2;
    //advance(itr2);  //advance by 2 positions 
    //itr2++;
    itr1 = lol.begin();
    itr2 = lol.begin();
    itr1++;
    lol.erase(itr2, itr1);  //range or single 
    cout<<"\nafter erasing:";
    print_list(lol);

    cout<<endl;
    lol.empty()? cout<<"empty\n":cout<<"not empty\n";
    cout<<lol.size();

    //lol.clear()
    //lol.swap()

    cout<<"\n\n___________________________\n";
}

void print_list(list<int> lol){
    cout<<endl;
    list<int>::iterator it;
    for(it = lol.begin(); it!= lol.end(); it++){
        cout<<*it<<" ";
    }
}