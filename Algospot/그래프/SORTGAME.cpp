#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;
map<vector<int>, int> toSort;
bool check[9];

void precalc() {
    // N개의 숫자를 가진 배열에 대한 연산 횟수들을 구한 적이 있다면 다시 구할 필요가 없다.
    if(check[N]) return;
    check[N] = true;
    
    vector<int> temp(N);
    for (int i = 0; i < N; i++) temp[i] = i;
    
    queue<vector<int> > que;
    que.push(temp);
    toSort[temp] = 0;
    
    while (!que.empty()) {
        vector<int> here = que.front();
        que.pop();
        
        // 현재 순열의 지금까지의 연산 횟수
        int cost = toSort[here];
        for (int i = 0; i < N; i++) {
            for (int j = i + 2; j <= N; j++) {
                // i부터 j-1까지 뒤집는다.
                
                reverse(here.begin() + i, here.begin() + j);
                
                // 뒤집은 순열을 만난적이 없다면 bfs의 특성상 최단거리이므로 해당 순열의 연산횟수를 +1 해준다
                if (toSort.count(here) == 0) {
                    toSort[here] = cost + 1;
                    que.push(here);
                }
                
                // 원상 복구
                reverse(here.begin() + i, here.begin() + j);
            }
        }
    }
}

void solve(){
    vector<int> temp(N);
    
    // 주어진 배열의 상대적 크기를 유지하면서 0~N-1 사이의 값으로 변환한다
    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(int j = 0; j < N; j++){
            if(arr[i] > arr[j]){
                cnt++;
            }
        }
        temp[i] = cnt;
    }
    
    
    // 변환된 배열을 통해서 정렬하기까지의 연산 횟수 출력
    cout << toSort[temp] << "\n";
}

int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> N;
        arr.resize(N, 0);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        precalc();
        solve();
        
        // toSort.clear();
    }
    
    return 0;
}
