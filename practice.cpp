#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto strings: strs){
            vector<int> freqArr(26,0);

            for(auto chars : strings){
                freqArr[chars-'a']++;
            }

            string anaGm = "";
            for(auto x: freqArr){
                anaGm += to_string(x);
            } //O(m)
        
            mp[anaGm].push_back(strings);
        }

        //-> 10^4(100 + log(10^4))  -> n(m+m+1)=> 2nm => nm
        vector<vector<string>> ans;
        for(auto entry: mp){
            ans.push_back(entry.second);
        }
        return ans;
    }
    // int reachedTop = 0;

    /*
    
    n = 2;
    global = 2, 

    rec(1)->rec(2), rec(3)

    rec(2)-> 

    n = 1, rec(1), rec(2)

    n = 3;
    global = 0

    rec(1),
        rec(2)  //1
            rec(3)  #inc  
            rec(4)  //1,2,1,4

        rec(3) #inc

    rec(2)
        rec(3) #inc
        rec(4)

    

    */

    int climbRecursive(int currentStep, int destiantionStep, vector<int>& visitedProbn){
        if(currentStep>destiantionStep) return 0;
       
        if(currentStep==destiantionStep){
            return 1;
        }
        if(visitedProbn[currentStep]!=-1) return visitedProbn[currentStep];

        return visitedProbn[currentStep] = climbRecursive(currentStep+1, destiantionStep, visitedProbn) + 
               climbRecursive(currentStep+2, destiantionStep, visitedProbn);
    }

    int climbStairs(int n) {
        vector<int> visitedProbn(n+1, -1);
        climbRecursive(0,n, visitedProbn);
        for(auto x: visitedProbn){
            cout<<x<<',';
        }
        return visitedProbn[0];
    }
};
//O(n)
// 0-> 1-> 2 -> 3 n
// 0-> 2
// O(n^2)

int main(){
    Solution s;
    s.climbStairs(3);
    
    cout<<"\n__________\n";
}
/*


You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

n = 2


n <= 45

*/

/*







Given an array of strings strs, group the 
anagrams
 together. You can return the answer in any order.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

vector<int> vct(26, 0)
vct['e']++
vct['a']++
vct['t']++


unordered_map [vct] = "eat", "tea"



Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

nat 
tan 

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

In

















*/