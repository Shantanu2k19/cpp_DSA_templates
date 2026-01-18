#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int>& a, pair<int, int>& b){
    if(a.second<b.second) return true;
    if(a.second>b.second) return false;
    if(a.first<b.first) return true;
	if(a.first>b.first) return false;
    return true;
}
void sss(map<int, int>& M){
	vector<pair<int, int> > A;
	for (auto& it : M) {
		A.push_back(it);
	}

	sort(A.begin(), A.end(), cmp);

	for(auto x:A){
       cout<<x.first<<" "<<x.second<<endl;
    }
}

void func(vector<int> lol){
	sort(lol.begin(),lol.end());
	for(auto x:lol) cout<<x<<" ";

}

int main(){
	vector <int>lol{1,43,1,3,2};
	func(lol);
	for(auto x:lol) cout<<x<<" ";
}                                       