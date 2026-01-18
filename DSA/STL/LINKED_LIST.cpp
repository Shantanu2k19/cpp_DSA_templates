#include<bits/stdc++.h>
using namespace std;

//LINKED LIST USING STRUCTURE 
/*
struct Node{
    int data;
    struct Node* next;
};

void print(Node* head){
    struct Node* ptr;
    ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
}

void makeList(Node* &head, int d){
    struct Node* temp= (struct Node*) malloc(sizeof(struct Node));
    temp->data = d;
    temp->next = NULL;

    if(head==NULL){
        head = temp;
        return;
    }
    
    struct Node* lol=head;
    while(lol->next!=NULL){
        lol=lol->next;
    }
    lol->next=temp;
}

int main(){
    int n;
    n = 5;
    struct Node* head=NULL;
    int arr[n]= {1,2,3,4,5};
    for(int i=0;i<n;i++){
        makeList(head,arr[i]);
    }
    print(head);
    cout<<"\n\n_____________________\n";
}
*/



//LINKED LIST USING CLASS 
class node{
    public:
    int data;
    node* next;

    node(int d){
        next=NULL;
        data = d;
    }
};

void makeList(node* &head, int data){
    if(head==NULL){
        head=new node(data);
        return;
    }

    node *temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next = new node(data);
    return;
}

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int subtract(node* head, node* head2){
    node* temp1 = head;
    node* temp2 = head2;

    int l1=0,l2=0;

    while(temp1!=NULL){
        l1++;
        if(temp2!=NULL){
            l2++;
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }

    int sum1=0, var=pow(10,l1-1);
    temp1 = head;
    for(int i=0;i<l1;i++){
        sum1 = sum1 + temp1->data*var;
        var /= 10;
        temp1 = temp1->next;
    }

    int sum2=0;
    var=pow(10,l2-1);
    temp1 = head2;
    for(int i=0;i<l2;i++){
        sum2 = sum2 + temp1->data*var;
        var /= 10;
        temp1 = temp1->next;
    }

    int diff = sum1-sum2;

    l1 = log10(diff);


    l1 = pow(10,l1);
    node* ans = new node(diff/l1);
    node *gg = ans;
    diff %= l1;
    l1 /= 10;
    cout<<endl;
    while(l1>0){
        node* temp = new node(diff/l1);
        gg->next = temp;
        gg = gg->next;
    
        diff %= l1;
        l1 /= 10;
    }
    gg->next = NULL;
    cout<<endl;
    print(ans);
    cout<<endl;
    return 69;
}

int lengthOfList(node* head){
    int l = 0;
    while(head!=NULL){
        l++;
        head = head->next;
    }
    return l;
}

void insertZero(node* &head, int n){
    node* temp = new node(0);
    node* var = temp;
    n--;
    while(n--){
        node* temp2 = new node(0);
        temp->next = temp2;
        temp = temp->next;
    }
    temp->next = head;
    head = var;
}

node* subtractHelper(node* head1, node* head2, bool &borrow){
    if(head1==NULL && head2==NULL && borrow==0) return NULL;

    node* previous = subtractHelper(head1?head1->next:NULL, head2?head2->next:NULL, borrow);

    int d1 = head1->data;
    int d2 = head2->data;
    int sub=0;

    if(borrow){
        d1--;
        borrow = false;
    }
    if(d1<d2){
        borrow = true;
        d1 = d1+10;
    }

    sub = d1-d2;
    node* current = new node(sub);
    current->next = previous;
    print(current);
    cout<<endl;
    return current;
}
node* subtractList(node* head1, node* head2){
    if(head1==NULL && head2==NULL) return NULL;

    int l1 = lengthOfList(head1);
    int l2 = lengthOfList(head2);

    node* slist;
    node* blist;

    if(l1!=l2){
        //insert 0 in shorter one
        if(l1<l2){
            slist = head1;
            blist = head2;
            insertZero(slist,l2-l1); 
        }
        else{
            slist = head2;
            blist = head1;
            insertZero(slist, l1-l2); 
        }
    }
    else{
        //l1 = l2, find smaller
        node* temp1 = head1;
        node* temp2 = head2;
    
        while(head1){
            if(head1->data > head2->data) {
                slist = temp2;
                blist = temp1;
                break;
            }
            else if(head1->data < head2->data) {
                slist = temp1;
                blist = temp2;
                break;
            }
            head1 = head1->next;
            head2 = head2->next;
        }       
    }

    print(slist);
    cout<<endl;

    print(blist);
    cout<<endl;

    bool borrow = false;
    return subtractHelper(blist, slist, borrow);
}


int main(){
    int n;
    n = 3;
    node* head = NULL;
    int arr[n]= {1, 0, 0};

    for(int i=0;i<n;i++){
        makeList(head,arr[i]);
    }

    n = 2;
    node* head2 = NULL;
    int arr2[n]= {1, 2};

    for(int i=0;i<n;i++){
        makeList(head2,arr2[i]);
    }

    print(head);
    cout<<endl;
    print(head2);
    cout<<"\n\n";

    // node* ans = subtractList(head,head2);

    // cout<<"\n\n";
    // print(ans);
    // cout<<subtract(head,head2);
    cout<<"\n\n_____________________\n";
}