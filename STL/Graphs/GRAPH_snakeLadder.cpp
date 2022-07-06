#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph{
    unordered_map<T, list<T>> adjList;

    graph(){}

    void addEdge(T i, T j, bool bidir=true){
        adjList[i].push_back(j);
        if(bidir) adjList[j].push_back(i);
    }

    void 
};

int main(){
    // for(int i=0)
    cout<<"\n_____________________________\n";
}                                       