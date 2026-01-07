#include <iostream>
#include <vector>
#include <string>

using namespace std;

string DivideSquare(int** arr, int x, int y, int x1, int y1, int depth){
    //Check Square
    int total = 0;
    bool allzero = true;
    for(int i = x; i < x1; i++){
        for(int j = y; j < y1; j++){
            if(arr[i][j] == 1) allzero = false;
            total += arr[i][j];
        }
    }

    //instruct char

    if(total == depth * depth){
        return "1";
    }else if(allzero){
        return "0";
    }


    return "(" +
    DivideSquare(arr, x, y, (x + x1)/2, (y + y1)/2, depth/2) +
    DivideSquare(arr, x, (y + y1)/2, (x + x1)/2, y1, depth/2) +
    DivideSquare(arr, (x + x1)/2, y, x1, (y + y1)/2, depth/2) +
    DivideSquare(arr, (x + x1)/2, (y + y1)/2, x1, y1, depth/2) + ")";
    

}

void ResetBuffer(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    int N = 0;
    int **arr2d;
    string temp = "";

    cin >> N;

    arr2d = new int*[N];
    for(int i = 0; i<N; i++){
        arr2d[i] = new int[N];

        cin >> temp;

        for(int j = 0; j<N; j++){
            arr2d[i][j] = temp[j] - 48;
        }
    }

    cout << DivideSquare(arr2d,0,0,N,N,N);

    return 0;
}
