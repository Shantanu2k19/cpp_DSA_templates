#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void functionX(vector<int> &values){
    sort(values.begin(), values.end());
}

int main()
{
    vector<int> total;
    int n = 100;
    vector<int> values(10000);
    auto f = []() -> int { return rand() % 10000; };
    generate(values.begin(), values.end(), f);
    
    for(int i=0;i<n;i++){
        auto start = high_resolution_clock::now();
        functionX(values);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        // cout << "Time taken:"<< duration.count() << "us\n";
        total.push_back(duration.count());
    }
    cout<<"average : "<<accumulate(total.begin(), total.end(),0)/n<<endl;
    cout<<"\n____________________________\n" << endl;
	return 0;
}
