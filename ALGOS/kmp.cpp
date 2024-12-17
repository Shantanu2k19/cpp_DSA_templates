/*

kmp is used for string pattering finding in efficient way 
bruteforce approach will take O(m*n) time, 
but KMP takes O(m+n)

--> find occurence of pattern P in text T without backtracking 
--> uses LPS array, longest prefix suffix, to skip unnecessary comparisons.

https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void constructLPS(string pat, vector<int> &lps){
    lps[0]=0;  //string with len 0 will no no common pre or suff

    int j = 0;  //lps[0]
    int i=1;

    while(i<pat.size()){
        if(pat[i]==pat[j]){
            j++;
            lps[i]=j;
            i++;
            continue;
        }

        //mismatch
        if(j!=0){
            j = lps[j-1];
        }
        else{
            lps[i]=0;
            i++;
        }
    }
}


vector<int> search(string &pat, string &txt){
    int n = txt.size();
    int m = pat.size();

    vector<int> lps(m);
    vector<int> res;

    constructLPS(pat, lps);

    //search
    int i=0;
    int j=0;

    while(i<n){
        if(txt[i]==pat[j]){
            i++;
            j++;

            if(j==m){ //entire pattern match
                res.push_back(i-j);

                j = lps[j-1];
                //use lps of previous index, to skip unnecessary comparison
            }
        }

        else{ 
            if(j!=0){
                j = lps[j-1];
            }
            else 
                i++;
        }
    }
    return res;
}

int main(){
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";

    vector<int> res = search(pat, txt);

    for(auto x: res){
        cout<<x<<", ";
    }
    cout<<"\n__________\n";
}