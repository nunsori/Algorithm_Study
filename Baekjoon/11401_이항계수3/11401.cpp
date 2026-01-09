#include <iostream>

using namespace std;

long long Mul(long long ex, long long A, long long C){
    if(ex == 0) return 1 % C;
    if(ex == 1) return A % C;

    long long sample = Mul(ex / 2, A, C);
    long long square = (((sample % C) * (sample % C)) % C);

    return ((square % C) * ((ex % 2) ? (A % C) : 1) % C);

}

void ResetBuffer(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    long long N, K;

    long long R = 1000000007;
    long long total = 1;

    cin >> N >> K;

    total = N;
    // for(int i = N - 1; i > N - K; i--){
    //     total = ((total % R) * (i % R)) % R;
    // }

    for(int i = 1; i < K; i++){
        total = ((total % R) * (((N - i) % R))) % R;
    }

    long long fac = 1;

    for(int i = 1; i < K + 1; i++){
        fac = ((fac % R) * (i % R)) % R;
    }

    if(K == 0){
        cout << 1;
    }else{
        cout << ((total % R) * (Mul(R - 2, fac, R) % R)) % R;
    }

    //cout << total;


    return 0;
}