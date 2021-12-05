#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

// N: location num, M: destination
int N, M;

// first: location, second: moveRange
vector<pii > rickshawLocation;

void input(){
    cin >> N >> M;
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a;
        rickshawLocation.push_back({a, 0});
    }
    for(int i = 0; i < N; i++){
        cin >> b;
        rickshawLocation[i].second = b;
    }
}

struct DB{
    pii locationrange;
    int transferCnt;
};

int minAnswer = INF;

void solve(){
    queue<DB> que;
    
    que.push({rickshawLocation[0], 0});
    bool visited[100001];
    memset(visited, 0, sizeof(visited));
    visited[0] = true;
    
    // 확인한 지점 중 가장 멀리있는 위치(인력거 인덱스)
    int idx = 0;
    
    while(!que.empty()){
        int now = que.front().locationrange.first;
        int range = que.front().locationrange.second;
        int tcnt = que.front().transferCnt;
        que.pop();
        
        if(M <= now + range){
            minAnswer = min(minAnswer, tcnt);
        }
        
        int tempidx = idx+1;
        while(tempidx < N){
            if(visited[tempidx]){
                tempidx++;
                continue;
            }
            int iscanreach = rickshawLocation[tempidx].first;
            if(iscanreach <= now + range){
                visited[tempidx] = true;
                que.push({rickshawLocation[tempidx], tcnt+1});
                idx = max(idx, tempidx);
            }
            else break;
            tempidx++;
        }
    }
}

int main(){
    fastio
    input();
    solve();
    if(minAnswer == INF) cout << "-1";
    else cout << minAnswer;
    
    return 0;
}
