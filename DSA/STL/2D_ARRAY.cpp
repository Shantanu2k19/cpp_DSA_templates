#include<iostream>
using namespace std;

int timRequiredToRot(int** arr, int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
int main(){
    const int R = 3;
    const int C = 5;

    int **arr = (int**)malloc(R*sizeof(int*));

    for(int r=0;r<R;r++){
        arr[r] = (int*)malloc(C*sizeof(int));
    }
    int v[R][C] = { { 2, 1, 0, 2, 1 },
                    { 1, 0, 1, 2, 1 },
                    { 1, 0, 0, 2, 1 } };
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            arr[i][j] = v[i][j];
        }
    }

    timRequiredToRot(arr, R, C);

    for(int i=0;i<R;i++){
        free(arr[i]);
    }
    free(arr);


    //way 1 : using ** pointer
    //way 2 : r,c as static global variables and take int arr[r][c] 
    //way 3 : using vector
    cout<<"\n_______________________\n";
    return 0;
}