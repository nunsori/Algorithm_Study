#include <iostream>

using namespace std;

void ResetBuffer(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void PirntMatrix(int** arr, int N, int M){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << arr[i][j];
            if(j != M - 1) cout << " ";
        }
        cout << "\n";
    }
}

//지역함수내에서 생성해서 실제 변수에 반영안됨
void Input(int** arr1, int N1, int M1){
    arr1 = new int*[N1];
    for(int i = 0; i < N1; i++){
        arr1[i] = new int[M1];
        for(int j = 0; j < M1; j++){
            cin >> arr1[i][j];
        }
    }
}

int** MatrixMultiplication(int** arr1, int**arr2, int N1, int M1, int N2, int M2){
    int** result;

    result = new int*[N1];
    for(int i = 0; i < N1; i++){
        result[i] = new int[M2];

        for(int i2 = 0; i2 < M2; i2++){
            int temp = 0;
            for(int j = 0; j < M1; j++){
                temp += arr1[i][j] * arr2[j][i2]; 
            }

            result[i][i2] = temp;
        }
    }

    return result;
}

int main(){
    int** arr1;
    int** arr2;

    int N1,M1;
    int N2,M2;

    cin >> N1 >> M1;

    arr1 = new int*[N1];
    for(int i = 0; i < N1; i++){
        arr1[i] = new int[M1];
        for(int j = 0; j < M1; j++){
            cin >> arr1[i][j];
        }
    }

    cin >> N2 >> M2;

    arr2 = new int*[N2];
    for(int i = 0; i < N2; i++){
        arr2[i] = new int[M2];
        for(int j = 0; j < M2; j++){
            cin >> arr2[i][j];
        }
    }

    PirntMatrix(MatrixMultiplication(arr1, arr2, N1, M1, N2, M2), N1, M2);

    return 0;
}