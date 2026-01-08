#include <iostream>

using namespace std;

void ResetBuffer(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

long long Mul(long long ex, long long A, long long C){
    if(ex == 0) return 1 % C;
    if(ex == 1) return A % C;

    long long sample = Mul(ex / 2, A, C);
    long long square = (((sample % C) * (sample % C)) % C);

    return ((square % C) * ((ex % 2) ? (A % C) : 1) % C);

}


int main(){
    ResetBuffer();

    long long A, B, C;
    cin >> A >> B >> C;


    // 이렇게 해결하면 O(N)이 나와서 부적절
    // for(int i = 0; i < B; i++){
    //     temp = ((temp % C) * (A % C)) % C;
    // }

    cout << Mul(B,A,C);

    return 0;
}