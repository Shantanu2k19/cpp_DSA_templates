#include<bits/stdc++.h>
using namespace std;

class qu{
    public:
    int x,y;
    int time;
};

void printList(queue<qu> temp){
    while(!temp.empty()){
        qu lol = temp.front();
        cout<<lol.x<<" "<<lol.y<<" -> "<<lol.time<<endl;
        temp.pop();
    }
    cout<<"\n_____\n";
}

int timRequiredToRot(int** arr2, int r, int c){

    //printing the array, creating new one with extra 0
    int arr[r+2][c+2];
    memset(&arr[0][0],0, sizeof(arr));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr[i+1][j+1] = arr2[i][j];
        }
    }
    for(int i=0;i<r+2;i++){
        for(int j=0;j<c+2;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //traversing and adding into queue
    queue<qu> listt;
    int time = 0;
    for(int i=1;i<r+1;i++){
        for(int j=1;j<c+1;j++){
            if(arr[i][j]==2){
                qu ele;
                ele.x = i;
                ele.y = j;
                ele.time = time;
                listt.push(ele);
            }
        }
    }

    qu temp;
    temp.x = temp.y = temp.time = -1;
    listt.push(temp);

    queue<qu> forPrint;
    forPrint = listt;
    printList(forPrint);

    time++;

    while(!listt.empty()){
        qu ele;
        ele = listt.front();
        if(ele.time == -1){
            cout<<"\ntime passed - "<<time<<endl;
            listt.pop();

            if(!listt.empty()) {
                qu temp;
                temp.x = temp.y = temp.time = -1;
                listt.push(temp);

                printList(listt);
                for(int i=0;i<r+2;i++){
                    for(int j=0;j<c+2;j++){
                        cout<<arr[i][j]<<" ";
                    }
                    cout<<endl;
                }
                time++;
            }
            else break;
            continue;
        }

        //cout<<ele.x<<" "<<ele.y<<"->"<<ele.time<<endl;
        int i = ele.x;
        int j = ele.y;

        if(arr[i][j+1]==1){
            qu temp;
            temp.x = i;
            temp.y = j+1;
            temp.time = time;
            listt.push(temp);
            arr[i][j+1]=2;
        }
        if(arr[i+1][j]==1){
            qu temp;
            temp.x = i+1;
            temp.y = j;
            temp.time = time;
            listt.push(temp);
            arr[i+1][j]=2;
        }
        if(arr[i-1][j]==1){
            qu temp;
            temp.x = i-1;
            temp.y = j;
            temp.time = time;
            listt.push(temp);
            arr[i-1][j]=2;
        }
        if(arr[i][j-1]==1){
            qu temp;
            temp.x = i;
            temp.y = j-1;
            temp.time = time;
            listt.push(temp);
            arr[i][j-1]=2;
        }
        listt.pop();
    }

    for(int i=1;i<r+1;i++){
        for(int j=1;j<c+1;j++){
            if(arr[i][j]==1) return -1;
        }
    }
    return time-1;
}
int main(){
    const int R = 3;
    const int C = 3;

    int **arr = (int**)malloc(R*sizeof(int*));

    for(int r=0;r<R;r++){
        arr[r] = (int*)malloc(C*sizeof(int));
    }
    // int v[R][C] = { { 1, 1, 1, 1, 1 },
    //                 { 1, 0, 2, 1, 1 },
    //                 { 1, 0, 0, 1, 1 } };

    int v[R][C] = { { 2, 1, 1},
                    { 0, 1, 1},
                    { 1, 0, 1} };
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            arr[i][j] = v[i][j];
        }
    }

    cout<<timRequiredToRot(arr, R, C);

    for(int i=0;i<R;i++){
        free(arr[i]);
    }
    free(arr);
    cout<<"\n_______________________\n";
    return 0;
}