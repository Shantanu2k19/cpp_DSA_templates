#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    unordered_map<char, Node*> m;
    bool isTerminal;

    Node(char d){
        data = d;
        isTerminal = false;
    }
};

class trie{
    public:
    Node* root;

    trie(){
        root = new Node('\0');
    }

    void insert(string s){
        Node* temp = root;

        for(char ch : s){
            if(temp->m.count(ch)==0){
                //not found character
                Node* n = new Node(ch);
                temp->m[ch]=n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }

    int search(string s){
        Node* temp = root;
        for(char ch : s){
            if(temp->m.count(ch)==0) return -1;
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }

    //for SUFFIX, create all substrings and insert :( lol
    void insert_suffix(string s){
        for(int i=s.length();i>0;i--){
            string sub = s.substr(0,i);
            // cout<<"inserting "<<sub<<endl;
            insert(sub);
        }
    }
};

int main(){
    trie t;
    t.insert("apple");
    t.insert("a");
    // t.insert("shun");

    cout<<t.search("a");

    // cout<<t.search("shan")<<endl;
    // cout<<t.search("shantanu")<<endl;

    string ss = "suffix";
    t.insert_suffix(ss);
    for(int i=ss.length();i>0;i--){
        cout<<t.search(ss.substr(0,i))<<endl;
    }

    cout<<"\n_________________\n";
}