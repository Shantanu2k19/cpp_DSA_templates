#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin>>str;

    int len = str.length();
    for (int i = 0; i < len; i++){
        for (int kk = 1; kk <= len - i; kk++)
            cout << str.substr(i, kk) << endl;
    }
    cout<<"\n___________________________________________________________________\n";
	return 0;
}