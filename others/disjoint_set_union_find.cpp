/*

TC: n*const, where const ~ 4

*/

#include<bits/stdc++.h>
using namespace std;

class UnionSet{
public:
    int v;
    vector<int> par;
    vector<int> rank;

    UnionSet(int v){
        this->v = v;
        par.resize(v);
        for(int i=0;i<v;i++){
            par[i]=i; //self parent
        }
        rank.resize(v,0);
    }

    int findPar(int k){
        if(par[k]==k) return k;
        return par[k]=findPar(k);  //path compression
    }

    void unionByRank(int x, int y){  //union by rank
        int parX = findPar(x);
        int parY = findPar(y);

        if(parX == parY)
            return;

        if(rank[parX]<rank[parY]){
            par[parX] = parY;
        }
        else if(rank[parY]<rank[parX]){
            par[parY] = parX;
        }
        else{
            par[parY] = parX;
            rank[parX] = rank[parX]+1;
        }
    }
};

int main(){
    int V = 5;
    vector<pair<int, int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}
    };

    UnionSet u(5);
}