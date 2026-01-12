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

void PirntMatrix(long long** arr, long long N, long long M){
    for(long long i = 0; i < N; i++){
        for(long long j = 0; j < M; j++){
            cout << arr[i][j];
            if(j != M - 1) cout << " ";
        }
        cout << "\n";
    }
}

long long** MatrixMultiplication(long long** arr1, long long**arr2, long long N1, long long M1, long long N2, long long M2){
    long long** result;

    result = new long long*[N1];
    for(long long i = 0; i < N1; i++){
        result[i] = new long long[M2];

        for(long long i2 = 0; i2 < M2; i2++){
            long long temp = 0;
            for(long long j = 0; j < M1; j++){
                temp = ModulerAdd(temp, ModulerMul(arr1[i][j], arr2[j][i2], (long long)1000000007), (long long)1000000007);
                //temp += arr1[i][j] * arr2[j][i2]; 
            }

            result[i][i2] = temp;
        }
    }

    return result;
}




long long** Mul(long long ex, long long** arr1, long long N, long long** origin){
    if(ex == 0) return NULL;
    if(ex == 1){
        for(long long i = 0; i < N; i++){
            for(long long j = 0; j < N; j++){
                arr1[i][j] %= (long long)1000000007;
            }
        }

        return arr1;
    }

    long long** sample = Mul(ex / 2, arr1, N, origin);
    long long** square = MatrixMultiplication(sample, sample, N, N, N, N);

    if(ex % 2){
        return MatrixMultiplication(square, origin, N, N, N, N);
    }else{
        return square;
    }

}


int main(){
    long long N;

    long long **arr;
    long long **origin;

    arr = new long long*[2];
    origin = new long long*[2];

    arr[0] = new long long[2]{1, 1};
    arr[1] = new long long[2]{1, 0};

    origin[0] = new long long[2]{1, 1};
    origin[1] = new long long[2]{1, 0};


    cin >> N;

    cout << Mul(N,arr,2,origin)[0][1];

    return 0;
}
