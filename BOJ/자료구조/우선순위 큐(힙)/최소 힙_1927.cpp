#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> result, arr;
int N, x, s;

void update_heap(int node){
    if(x <= arr[node*2+1]){
        arr.insert(arr.begin()+node*2+1, x);
        return;
    }
    else if(x > arr[node*2+1] && x <= arr[node*2+2]){
        arr.insert(arr.begin()+node*2+2, x);
        return;
    }
    else if(arr[node*2+1] == 0){
        arr.insert(arr.begin()+node*2+1, x);
        return;
    }
    else if(arr[node*2+2] == 0){
        arr.insert(arr.begin()+node*2+2, x);
        return;
    }
    else{
        update_heap(node*2 + 1);
        update_heap((node+1) * 2);
    }
}

void heap(){
    if(s == 0){
        arr.insert(arr.begin(), x);
        s++;
    }
    else if(x <= arr[0]){
        arr.insert(arr.begin(), x);
        s++;
    }
    else{
        update_heap(0);
    }
}

void solve(){
    for(int i = 0; i < N; i++){
        cin >> x;
        if(x == 0){
            if(arr.size() == 0){
                result.push_back(0);
            }
            else{
                result.push_back(arr[0]);
                arr.erase(arr.begin());
                s--;
            }
        }
        else{
            heap();
        }
    }
    for(auto w : result){
        cout << w << "\n";
    }
}

int main(){
    cin >> N;
    arr.reserve(100001);
    solve();

    return 0;
}
