#include <iostream>

using namespace std;

void ResetBuffer(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    int N, K;

    int R = 1000000007;
    int total = 1;

    cin >> N >> K;

    total = N;
    // for(int i = N - 1; i > N - K; i--){
    //     total = ((total % R) * (i % R)) % R;
    // }

    for(int i = 1; i < K; i++){
        total = ((total % R) * (((N - i) % R))) % R;
    }

    int fac = 1;

    for(int i = 1; i < K + 1; i++){
        fac 
    }

    cout << total;


    return 0;
}