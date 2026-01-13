#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct HEAP{
    T* arr;
    int last = 0;

    void Init(int n){
        arr = new T[n];
        arr[0] = -1;
        last = 0;
    }

    int Insert(T value){
        last++;
        arr[last] = value;
        

        int temp = last;
        int temp2 = 0;
        while(temp >= 2){
            if(arr[temp] > arr[temp / 2]){
                temp2 = arr[temp];
                arr[temp] = arr[temp / 2];
                arr[temp / 2] = temp2;
            }else{
                break;
            }

            temp /= 2;
        }

        //print();
        return 1;

    }

    int Delete(){
        if(last == 0){
            return 0;
        }
        int return_value = arr[1];
        arr[1] = 0;
        arr[1] = arr[last];
        arr[last] = 0;
        last--;

        if(last < 0){
            last = 0;
            return return_value;
        }

        int temp = 1;
        int temp2 = 0;
        while(true){
            if(temp * 2 > last){
                break;
            }
            
            int child = temp * 2;
            if(temp * 2 + 1 <= last && arr[temp * 2 + 1] > arr[temp * 2]){
                child = temp * 2 + 1;
            }

            if(arr[child] > arr[temp]){
                temp2 = arr[temp];
                arr[temp] = arr[child];
                arr[child] = temp2;

                temp = child;
            }else{
                break;
            }

            
        }   
        //print();
        return return_value;
    }

    void print(){
        for(int i = 0; i < last + 1; i++){
            cout << arr[i] << " ";
        }

        cout <<"\n";
    }
};


void ResetBuffer(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    HEAP<int> heap = HEAP<int>();
    string outtemp = "";

    int N = 0;
    int temp = 0;
    cin >> N;

    heap.Init(N + 1);

    for(int i = 0; i < N; i++){
        cin >> temp;
        if(temp == 0){
            outtemp += (to_string(heap.Delete()) + "\n");
        }else{
            heap.Insert(temp);
        }
    }

    cout << outtemp;

    return 0;
}