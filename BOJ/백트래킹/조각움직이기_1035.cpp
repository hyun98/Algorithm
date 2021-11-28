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


vector<int> firstsector;
int firstState;
int ANS = INF;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void input(){
    string str;
    for(int i = 0; i < 5; i++){
        cin >> str;
        for(int j = 0; j < 5; j++){
            if(str[j] == '*'){
                firstsector.push_back(i*5 + j);
                firstState |= (1 << (i*5 + j));
            }
        }
    }
}

vector<pii > changeDemension(int state){
    // 1차원 5x5 좌표에서 2차원으로 변환 
    vector<pii > fraclist;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(((state >> (i*5 + j)) & 1) == 1){
                fraclist.push_back({i, j});
            }
        }
    }
    return fraclist;
}

int findDistance(int targetState, vector<int> &order){
    vector<pii > now = changeDemension(targetState);
    vector<pii > fst = changeDemension(firstState);
    int dist = 0;
    pii a, b;
    int hx = 0, hy = 0;
    
    for(int i = 0; i < order.size(); i++){
        int ord = order[i];
        a = now[i];
        b = fst[ord];
        hx = abs(a.first - b.first);
        hy = abs(a.second - b.second);
        dist += (hx + hy);
    }
    return dist;
}

bool ovisited[5];
void distOptimize(int n, int targetState, vector<int> &order, int &tans){
    if(n == firstsector.size()){
        tans = min(tans, findDistance(targetState, order));
        return;
    }
    
    for(int i = 0; i < firstsector.size(); i++){
        if(ovisited[i]) continue;
        ovisited[i] = true;
        order.push_back(i);
        distOptimize(n+1, targetState, order, tans);
        order.pop_back();
        ovisited[i] = false;
    }
    
}

bool isLinked(int state){
    vector<pii > now = changeDemension(state);
    bool visited[6][6];
    memset(visited, 0, sizeof(visited));
    
    queue<pii > que;
    que.push(now[0]);
    visited[now[0].first][now[0].second] = true;
    
    int cnt = 1;
    
    while(!que.empty()){
        pii n = que.front();
        que.pop();
        
        if(cnt == now.size()){
            return true;
        }
        
        for(int i = 0; i < 4; i++){
            int nr = n.first + dr[i];
            int nc = n.second + dc[i];
            if(nr < 0 || nr >= 5 || nc < 0 || nc >= 5 || visited[nr][nc]) continue;
            if(!((1 << (nr*5 + nc)) & state)) continue;
            
            visited[nr][nc] = true;
            cnt++;
            que.push({nr, nc});
        }
    }
    return false;
}


void makeNewState_Solve(int n, int prev, int state){
    if(n == firstsector.size()){
        if(isLinked(state)){
            // int tans = findDistance(state);
            // ANS = min(ANS, tans);
            vector<int> order;
            memset(ovisited, 0, sizeof(ovisited));
            distOptimize(0, state, order, ANS);
        }
        return;
    }
    
    for(int i = prev; i < 25; i++){
        makeNewState_Solve(n+1, i+1, state|(1 << i));
    }
}

void solve(){
    // state만들기
    makeNewState_Solve(0, 0, 0);
    cout << ANS;
}

int main(){
    input();
    solve();
    
    return 0;
}
