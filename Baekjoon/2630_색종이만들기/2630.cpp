#include <iostream>

using namespace std;

void ResetBuffer(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DivideSquare(int** arr, int x, int y, int x1, int y1, int depth, int* tZ, int* tO){
    //Check Square
    int total = 0;
    bool allzero = true;
    for(int i = x; i < x1; i++){
        for(int j = y; j < y1; j++){
            if(arr[i][j] == 1) allzero = false;
            total += arr[i][j];
        }
    }

    if(total == depth * depth){
        *tZ += 1;
        return;
    }else if(allzero){
        *tO += 1;
        return;
    }

    DivideSquare(arr, x, y, (x + x1)/2, (y + y1)/2, depth/2, tZ, tO);
    DivideSquare(arr, (x + x1)/2, y, x1, (y + y1)/2, depth/2, tZ, tO);
    DivideSquare(arr, x, (y + y1)/2, (x + x1)/2, y1, depth/2, tZ, tO);
    DivideSquare(arr, (x + x1)/2, (y + y1)/2, x1, y1, depth/2, tZ, tO);
    

}

int main(){
    ResetBuffer();
    
    int N = 0;
    int **arr2d;

    int totalZero=0;
    int totalOne=0;

    int* tZ = &totalZero;
    int* tO = &totalOne;

    *tZ = 0;
    *tO = 0;

    cin >> N;

    arr2d = new int*[N];
    for(int i = 0; i<N; i++){
        arr2d[i] = new int[N];

        for(int j = 0; j<N; j++){
            cin >> arr2d[i][j];
        }
    }

    DivideSquare(arr2d, 0, 0, N, N, N, tZ, tO);

    cout << *tO << "\n" << *tZ;

    return 0;
}