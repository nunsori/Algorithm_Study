#include <iostream>

using namespace std;

void ResetBuffer(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

template <typename T>
T ModulerAdd(T a, T b, T c){
    return ((a % c) + (b % c)) % c;
}

template <typename T>
T ModulerMul(T a, T b, T c){
    return ((a % c) * (b % c)) % c;
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

int** MatrixMultiplication(int** arr1, int**arr2, int N1, int M1, int N2, int M2){
    int** result;

    result = new int*[N1];
    for(int i = 0; i < N1; i++){
        result[i] = new int[M2];

        for(int i2 = 0; i2 < M2; i2++){
            int temp = 0;
            for(int j = 0; j < M1; j++){
                temp = ModulerAdd(temp, ModulerMul(arr1[i][j], arr2[j][i2], 1000), 1000);
                //temp += arr1[i][j] * arr2[j][i2]; 
            }

            result[i][i2] = temp;
        }
    }

    return result;
}




int** Mul(long long ex, int** arr1, int N, int** origin){
    if(ex == 0) return NULL;
    if(ex == 1) return arr1;

    int** sample = Mul(ex / 2, arr1, N, origin);
    int** square = MatrixMultiplication(sample, sample, N, N, N, N);

    if(ex % 2){
        return MatrixMultiplication(square, origin, N, N, N, N);
    }else{
        return square;
    }

}


int main(){
    int** arr;
    int** origin;
    int N;
    long long B;

    cin >> N >> B;

    arr = new int*[N];
    origin = new int*[N];
    for(int i = 0; i < N; i++){
        arr[i] = new int[N];
        origin[i] = new int[N];
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            origin[i][j] = arr[i][j];
        }
    }


    PirntMatrix(Mul(B,arr,N,origin), N, N);

    return 0;
}