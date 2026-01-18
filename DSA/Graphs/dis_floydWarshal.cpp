#include<bits/stdc++.h>
using namespace std;

class graph{
    public:

    int v;
    vector<vector<int>> mat;

    graph(int v){
        this->v = v;
        mat.resize(v, vector<int>(v, INT_MAX));
    }

    void createMatrix(vector<vector<int>> &edges){
        for(auto x: edges){
            int src = x[0];
            int des = x[1];
            int dis = x[2];

            mat[src][des] = dis;
        }

        for(int i=0;i<v;i++){
            mat[i][i]=0;
        }
    }

    void floydWarshal(){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                for(int k=0; k<v; k++){
                    //dis b/w j,k via i
                    int src = j;
                    int des = k;
                    int via = i;

                    if(mat[src][via]==INT_MAX || mat[via][des]==INT_MAX)
                        continue;
                    if(mat[src][des]>mat[src][via]+mat[via][des]){
                        mat[src][des]=mat[src][via]+mat[via][des];
                    }
                }
            }
        }

        //print distance matrix

        /*
        
        If any value is negative in matrix, thr graph contains negative edge cycle 
        */
        cout<<"\t";
        for(int j=0;j<v;j++){
            cout<<j<<"\t";
        }
        cout<<"\n\n";

        for(int i=0;i<v;i++){
            cout<<i<<"\t";
            for(int j=0;j<v;j++){
                mat[i][j]==INT_MAX? cout<<"inf\t" : cout<<mat[i][j]<<"\t";
            }
            cout<<endl;
        }
    }


    
};

int main(){
    
    /*

          10
    (0)------->(3)
     |         /|\
   5 |          |
     |          | 1
    \|/         |
    (1)------->(2)
          3    
            
    */

   vector<vector<int>> edges = {{0,3,10}, {0,1,5}, {1,2,3}, {2,3,1}};
   graph g(4);
   g.createMatrix(edges);

   g.floydWarshal();

   cout<<"\n______________\n";

}