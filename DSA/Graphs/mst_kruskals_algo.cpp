/*

TC: O(mlog(n)) + O(m*4a) ==> mlog(n)
*/

#include<bits/stdc++.h>
using namespace std;

class kruskals{
protected:
    int n;
    //have an list with {dis, src, des}, sort it 
    vector<vector<int>> sortByWeight;
    vector<int> par;
    vector<int> rank;

    int findPar(int k){
        if(par[k]==k) return k;
        return par[k]=findPar(par[k]);
    }

  public:
    kruskals(int v){
        this->n = v;
        par.resize(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }

        rank.resize(n,0);
    }

    void makeUnion(int a, int b){
        if(rank[a]<rank[b]){
            par[a] = b;
        }
        else if(rank[b]<rank[a]){
            par[b] = a;
        }
        else {
            //rank[a]==rank[b]
            par[a] = b;
            rank[b]++;
        }
    }

    void kruskalAlgo(vector<vector<pair<int, int>>> &adj){
    
        for(int src=0;src<n;src++){
            for(auto x: adj[src]){
                int nbr = x.first;
                int dis = x.second;

                sortByWeight.push_back({dis, src, nbr});
            }
        }
        sort(sortByWeight.begin(), sortByWeight.end());

        //kruskals
        vector<vector<int>> mst;

        for(int i=0;i<sortByWeight.size();i++){
            int wei = sortByWeight[i][0];
            int a = sortByWeight[i][1];
            int b = sortByWeight[i][2];
            
            int parA = findPar(a);
            int parB = findPar(b);
            
            if(parA == parB){
                continue;
            }

            makeUnion(a, b);
            mst.push_back({a,b,wei});
        }

        for(auto x: mst){
            cout<<x[0]<<"->"<<x[1]<<"  : "<<x[2]<<endl;
        }
    }
};



int main(){
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);

    vector<tuple<int, int, int>> edges = {
        {0, 1, 2}, {0, 2, 1}, {2, 1, 1}, {2, 4, 2}, {2, 3, 2}, {3, 4, 1}
    };

    /*
           2  
        0----1    4
        |   /    /|
      1 | 1/  2/  |1
        | /  /    |
        |/ /      |
        2---------3
             2
    */

    for(auto [a, b, dis]: edges){
        adj[a].push_back({b, dis});
        adj[b].push_back({a, dis});
    }

    kruskals k(n);
    k.kruskalAlgo(adj);

    cout<<"\n______\n";
}