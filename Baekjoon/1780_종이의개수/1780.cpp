#include <iostream>

using namespace std;

void DivideSquare(int** arr, int sx, int sy, int depth, int* Zero, int* One, int* Minus){
    //Check 
    int total = 0;
    bool allzero = true;
    for(int i = sx ; i < sx + depth; i++){
        for(int j = sy; j < sy + depth; j++){
            total += arr[i][j];
            if(arr[i][j] != 0) allzero = false;
        }
    }

    if(allzero){
        *Zero += 1;
        return;
    }
    if(total == depth * depth){
        *One += 1;
        return;
    }else if(total == -(depth * depth) ){
        *Minus += 1;
        return;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            DivideSquare(arr, sx + (depth/3) * (i), sy + (depth/3) * (j), depth/3, Zero, One, Minus);
        }
    }
}


void ResetInOutput(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    ResetInOutput();

    int N = 0;
    int** arr2d;

    int zero = 0;
    int one = 0;
    int minus = 0;

    cin >> N;

    arr2d = new int*[N];
    for(int i = 0; i < N; i++){
        arr2d[i] = new int[N];
        for(int j = 0; j < N; j++){
            cin >> arr2d[i][j];
        }
    }

    DivideSquare(arr2d, 0, 0, N, &zero, &one, &minus);

    cout << minus << "\n" << zero << "\n" << one;

    return 0;
}