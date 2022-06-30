#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    char data;
    node* children[26]; 
    bool isBan;
    bool isTerminal;
    int frequency;
    int tim;

    node (char d, bool it=false) {
        data=d; 
        isTerminal = it; 
        for (int i=0;i<26;i++) children[i]=NULL;
    }
};

node* root;
int timee;

void init(){
    root = new node('\0');
    timee=0; 
}

void inputword(char ele[20]){
    node* temp = root; 
    int i=0;
    while(ele[i]!= '\0'){
        if(temp->children[ele[i]-97]==NULL){ 
            node* n = new node (ele[i]); 
            temp->children[ele[i]-97]=n;
        }
        temp = temp->children[ele[i]-97];
        i++;
    } 
    
    if(temp->isTerminal) temp->frequency++;
    else temp->isTerminal=true;

    temp->tim = timee;
    timee++;
}

void displayTrie(node* root, string s){
    if(root->isTerminal and  s!="" and s!=" "){
        s = s+root->data;
        cout<<s<<" freq->"<<root->frequency<<", time->"<<root->tim<<" ban:"<<root->isBan<<endl;
    }

    for(int i=0;i<26;i++){
        if(root->children[i]!=NULL){
            if(root->data!='\0') displayTrie(root->children[i], s+root->data);
            else displayTrie(root->children[i], s);
        }
    }
}

void findBest (node* temp, string s, vector< pair<node*, string> > &lol) {
    //base case
    if(temp->isTerminal and (temp->isBan==false)){
        //thats a word
        lol.push_back({temp, s+temp->data});
    }

    for (int i=0; i<26; i++) {
        if(temp->children[i]!=NULL) {
            //word here
            findBest (temp->children[i], s+temp->data, lol);
        }
    }
}

bool comp(pair<node*, string> a, pair<node*, string> b){ 
    if(a.first->frequency>b.first->frequency) return true; 
    else if(a.first->frequency<b.first->frequency) return false;
    return a.first->tim>b.first->tim;
}

int recommend (char ele[20], char mAnswer[20]){
    cout<<endl;
    //displayTrie(root,""); 
    // cout<<"recommending\n";
    node* temp = root;
    int i=0;
    while(ele[i]!= '\0'){
        if(temp->children[ele[i]-97]==NULL){
            cout<<"\nno word found.\n";
            //element not in trie
            //return itself, and its length
            int t = 0;
            while(ele[t]!='\0' ){
                mAnswer[t] = ele[t] ;
                t++;
            }
            return --t;
        }

        //character found
        temp = temp->children[ele[i]-97];
        i++;
    }
    // cout<<temp->data<<endl;

    //stri..
    //completed all elements of ele, now recommend //for every word with that prefix, traverse and find best

    string s = ele;
    // cout<<"\ncurr: "<<s<<endl;
    s.pop_back();

    vector< pair<node*, string> > lol;
    findBest(temp, s, lol);
    // cout<<endl<<"before sorting \n";

    // for(auto x : lol){
    //     cout<<x.second<<endl;
    // }

    if(lol.size()==0){
        cout<<"one word only";
        //return
        int t = 0;
        while(ele[t] != '\0') {
            mAnswer[t] = ele[t];
            t++;
        };
        return t--;
    }

    sort (lol.begin(), lol.end(), comp); 

    cout<<endl<<"after sorting \n";

    for(auto x : lol){
        cout<<x.second<<endl;
    }

    auto c = lol[0].second;
    for(int i=0; i<c.length(); i++) mAnswer [i] = c[i] ;
    cout<<"\nfound : "<<c<<endl;
    return c.length();
}

void banWord(char ele[20]){
    node* temp = root;
    int i = 0;
    while(ele[i]!='\0') {
        if(temp->children[ele[i]-97]==NULL){
            node* n = new node (ele[i]); 
            temp->children[ele[i]-97]=n;
        }
        temp = temp->children[ele[i]-97];
        i++;
    }
    
    if(temp->isTerminal==false) temp->isTerminal=true;
    if(temp->isBan==false) temp->isBan=true;
}

void printWord(char lol[20]){
    int i=0;
    while(lol[i]!='\0'){
        cout<<lol[i++];
    }
    cout<<endl;
}



void find(string s){
    node* temp = root;
    for(char x: s){
        if(temp->children[x-97]==NULL) {cout<< "not found\n"; return;};
        temp = temp->children[x-97];
    }
    temp->isTerminal ? cout<<"found\n" : cout<<"not found\n";
}

int main(){
    init();

    char temp2[20];

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        char temp[20]={'\0'};
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++){
            temp[i]=s[i];
        }

        switch(n){
            case(1):inputword(temp);
                    break;
            case(2):recommend(temp,temp2);
                    break;
            case(3):find("shan");
                    break;
            case(4):{
                    cout<<"\nprinting\n";
                    displayTrie(root,""); 
                    }
                    break;
            case(5):banWord(temp);
                    break;
            default:cout<<"nope";
                    break;
        }
    }
    // recommend(name, temp);
    // printWord(temp);

    cout<<"\n___________________\n";
}