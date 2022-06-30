#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    string name;
    list<string> nbrs;

    node(string nam){
        this->name = nam; 
    }
};

class graph{
    unordered_map<string, node*> m;
    public:
    graph(vector<string> cities){
        for(auto city: cities){
            m[city]=new node(city);
        }
    } 

    void addEdge(string x, string y, bool undir=true){
        m[x]->nbrs.push_back(y);
        if(undir){
            m[y]->nbrs.push_back(x);
        }
    }

    void printAdjList(){
        for(auto cityPair: m){
            auto city = cityPair.first;
            node* node = cityPair.second;

            cout<<city<<"->";
            for(auto nbr: node->nbrs){
                cout<<nbr<<",";
            }
            cout<<endl;
        }
    }

};

int main(){
    vector<string> cities={"delhi", "mumbai", "pune", "paris"};
    graph g(cities);

    g.addEdge("delhi", "pune");
    g.addEdge("mumbai", "pune");
    g.addEdge("delhi", "paris");
    g.printAdjList();

    cout<<"\n_____________________________\n";
}                                       