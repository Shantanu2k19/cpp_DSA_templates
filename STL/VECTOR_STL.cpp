#include <bits/stdc++.h>
using namespace std;

//SORTING IN DESCENDING ORDER
struct Interval {
   int start, end;
};

// Compares two intervals according to staring times.
bool compareInterval(Interval i1, Interval i2){
   return (i1.start > i2.start);
};


//INITIALIZE VECTOR
// int n;
// cin>>n;
// vector<int> arr(n,-1);

//2d vector
// vector< vector<int> > dp(3, vector<int> (2,-1));  //3 rows, 2 columns,  initialize with -1


int main() {
   //Vector 
   vector<int> lol;
   lol.push_back(20);
   lol.push_back(69);
   lol.push_back(5);

   cout<<"at: "<<lol.at(2)<<", []: "<<lol[2]<<endl;

   //SORTING
   sort(lol.begin(),lol.end());
   //sort(lol.begin(),lol.end(), greater<int>()); //in descending order

   //DELETING
   lol.erase(lol.begin()+2);  //remove 2nd element 

   for(auto it=lol.begin();it!=lol.end();it++){   //for(auto itr:lol)
      cout<<*it<<"-";
   }

   //SEARCHING
   vector<int>::iterator itr;
   itr = std::find(lol.begin(),lol.end(),209);
   itr!=lol.end()? cout<<"\nfound! \n":cout<<"\nnot found\n";

   // auto ptr=find(arr,arr+n,key);
   // (ptr-arr)==n ? cout<<"ele not found!" : cout<<"index of ele : "<<(ptr-arr); 
      
   cout<<endl;

   //INSERTING AT SPECIFIC LOCATION 
   // lol.insert(lol.begin(), 69);




   //Vector of vector 
   cout<<"\nVector of vector\n"; 
   vector < vector<int> > arr;
   
   for(int i=0;i<5;i++){
      vector<int> lol;
         for(int k=0;k<2;k++){
            lol.push_back(i*i);
         }
      arr.push_back(lol);
   }
   
   for(int i=0;i<arr.size();i++){
      for(int j=0;j<arr[i].size();j++){
         cout<<arr[i][j]<<",";
      }
      cout<<"\n";
   }


   vector<Interval> v { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
  
   sort(v.begin(), v.end(), compareInterval);
   for (auto x : v)
      cout << "[" << x.start << ", " << x.end << "] ";

   

   ///////  END  /////
    cout<<"\n___________________________________________________________________\n";
	return 0;
}
