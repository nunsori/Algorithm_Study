#include <iostream>
#include <queue>
#include <vector>


using namespace std;


struct Cmp{
    bool operator()(const priority_queue<int>& a, const priority_queue<int>& b) const{
        if(a.top() != b.top()) return a.top() < b.top();
        return a.top() > b.top();
    }
};

void ResetBuffer(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    ResetBuffer();

    int N;
    priority_queue<priority_queue<int>, vector<priority_queue<int>>,Cmp> qArr;

    cin >> N;

    for(int i = 0; i < N; i++){
        priority_queue<int> tempq = priority_queue<int>();
        int temp = 0;
        for(int j = 0; j < N; j++){
            cin >> temp;
            tempq.push(temp);
        }

        qArr.push(tempq);
    }

    for(int i = 0; i < N - 1; i++){
        auto pq = qArr.top();
        qArr.pop();
        pq.pop();
        qArr.push(pq);
    }

    cout << qArr.top().top();


    return 0;
}