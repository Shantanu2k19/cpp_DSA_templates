#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Node{
    public:
    char data;
    map<char, Node*> m;  //map a given key with address
    bool isTerminal;

    Node(char d){
        data = d;
        isTerminal = false;
    }
};

class Trie{
    public:
    Node* root;

    Trie(){
        root = new Node('\0');
    }

    void Insert(string word){
        Node* temp = root;

        for(char ch: word){
            if(temp->m.count(ch)==0){   //if character not in map
                //create new node
                Node* n=new Node(ch);
                temp->m[ch]=n;  //add that node to map of root node
            }

            //move to next char/node in trie
            temp = temp->m[ch];
        }

        //reached end
        temp->isTerminal = true;
    }

    bool Search(string word){
        Node* temp = root;
        for(char ch: word){
            if(temp->m.count(ch)==0) return false;

            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }

    void display(Node* temp, string prev=""){
        if(temp==NULL) return;

        // if(temp->isTerminal) 
        cout<<prev<<endl;
        for(auto x: temp->m){
            display(x.second, prev+x.first);
        }
    }
};

int main(){
    // string words[] = {"apple", "ball", "cat","call"};
    // Trie t;
    // for(auto itm : words){
    //     t.Insert(itm);
    // }
    // t.display(t.root);
    // cout<<t.Search("app")<<endl;

    string lol ="The history of Earth Day goes back to the seventies. In the year 1970, people actually realized the grave conditions of our planet and began putting effort into protecting it. 1970 was the first year when Earth Day was celebrated. Millions of people were involved. People took to the streets, asking the government to take steps to protect nature. People from all walks of life gathered and pledged to take care of mother Earth. This way, they showed respect for mother nature and brought environmental problems to people’s attention the US, but soon the event became global, and countries worldwide began celebrating it. Today, more than 190 countries celebrate World Earth Day each year on April 22. The celebration involves programs and events dedicated to protecting nature, cutting down pollution, and learning about environmental protection.";
    string temp="";
    vector<string> test;
    for(int i=0;i<lol.length();i++){
        int kk = lol[i]-'a';
        if(lol[i]==' '){
            test.push_back(temp);
            temp="";
        }
        if(kk>=0 and kk<=25){
            temp+=lol[i];
        }
    }

    vector<int> total;
    int n = 10;
    for(int i=0;i<n;i++){
        auto start = high_resolution_clock::now();
        
         Trie t;
        //insertion
        for(int i=0;i<test.size();i++){
            t.Insert(test[i]);
        }
        //searching
        for(int i=0;i<test.size();i++){
            t.Search(test[i]);
        }
        //display
        t.display(t.root);


        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        // cout << "Time taken:"<< duration.count() << "us\n";
        total.push_back(duration.count());
    }
    cout<<"average : "<<accumulate(total.begin(), total.end(),0)/n<<endl;

    cout<<"\n_____________________________\n";
}                                       