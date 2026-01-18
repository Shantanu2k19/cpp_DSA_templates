#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

//class node to store data (linked list)
class Node{
    public:
    string key;
    int value;
    Node(string key, int val){
        this->key = key;
        this->value = val;
    }
};


//LRU cache data structure 
class LRUCache{
    public:
    int maxSize;
    list<Node> l;
    unordered_map<string, list<Node>::iterator> m;

    LRUCache(int maxx){
        this->maxSize = maxx>1? maxx:1;
    }

    void insertKeyValue(string key,int value){
        if(m.count(key)!=0){ //exist, update value
            auto it = m[key];
            it-> value = value;
        }
        else{
            //check if cache is full
            if(l.size()==maxSize){
                //remove least recently used item from list
                Node last = l.back();
                m.erase(last.key);
                l.pop_back();
            }
        
            Node n(key,value);
            l.push_front(n);
            m[key] = l.begin();
        }
    }

    int* getValue(string key){
        if(m.count(key)!=0){
            auto it = m[key];

            l.push_front(*it);
            l.erase(it);
            m[key]=l.begin();
            return &l.begin()->value;
        }
        return NULL;
    }

    string mostRecentKey(){
        return l.front().key;
    }

    void printLRU(){
        for(auto x : l){
            cout<<x.key<<"-"<<x.value<<endl;
        }
    }
};


int main(){
    LRUCache lru(4);
    lru.insertKeyValue("mango", 10);
    lru.insertKeyValue("apple", 20);
    lru.insertKeyValue("guava", 30);

    lru.printLRU();

    cout<<lru.mostRecentKey()<<endl;

    lru.insertKeyValue("mango",40);

    cout<<lru.mostRecentKey()<<endl;

    lru.insertKeyValue("banana",20);

    if(lru.getValue("apple")==NULL){
        cout<<"apple does not exist!\n";
    }

    if(lru.getValue("guava")==NULL){
        cout<<"guava does not exist!\n";
    }

    if(lru.getValue("banana")==NULL){
        cout<<"banana does not exist!\n";
    }

    if(lru.getValue("mango")==NULL){
        cout<<"mango does not exist!\n";
    }
    
    cout<<"\n_________________\n";
}