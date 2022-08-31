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

int N, M;

int Map[51][51], originMap[51][51];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
bool check[11];
bool visited[51][51];
int answer = INF;
vector<pii > virusCandidate;

void input(){
    cin >> N >> M;
    int a;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a;
            if(a == 2){
                virusCandidate.push_back({i, j});
                Map[i][j] = 0;
                originMap[i][j] = 0;
            } else {
                Map[i][j] = a;
                originMap[i][j] = a;
            }
        }
    }
    
}

void clear_all(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            Map[i][j] = originMap[i][j];
            visited[i][j] = false;
        }
    }
}

void virus_spread(vector<pii >& virus){
    queue<pii > que;
    while(!virus.empty()){
        que.push(virus.back());
        visited[virus.back().first][virus.back().second] = true;
        virus.pop_back();
    }
    
    while(!que.empty()){
        pii now = que.front();
        que.pop();
        
        for(int i = 0; i < 4; i++){
            int nr = dr[i] + now.first;
            int nc = dc[i] + now.second;
            
            if(visited[nr][nc]) continue;
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(Map[nr][nc] == 0){
                visited[nr][nc] = true;
                Map[nr][nc] = 2;
                virus.push_back({nr, nc});
            }
        }
    }
}

void printall(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << Map[i][j] << " ";
        }
        cout << '\n';
    }
}

bool virus_all_check(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(Map[i][j] == 0) return false;
        }
    }
    return true;
}

int solve(vector<pii >& selected_virus){
    clear_all();
    
    vector<pii > sv = selected_virus;
    
    int times = 0;
    
    for(auto p: sv){
        Map[p.first][p.second] = 2;
    }
    // if(sv.empty()) return INF;
    if(virus_all_check()) return times;
    while(true){
        times++;
        virus_spread(sv);
        if(virus_all_check()) return times;
        if(sv.empty()) return INF;
    }
    
    return times;
}

void selectVirusBlock_backtracking(int m, vector<pii >& selected){
    if(selected.size() == M){
        answer = min(answer, solve(selected));
        return;
    }
    
    for(int i = m; i < virusCandidate.size(); i++){
        if(check[i]) continue;
        check[i] = true;
        selected.push_back(virusCandidate[i]);
        selectVirusBlock_backtracking(i+1, selected);
        selected.pop_back();
        check[i] = false;
    }
}


int main(){
    input();
    vector<pii > selected;
    selectVirusBlock_backtracking(0, selected);
    
    if(answer == INF) cout << -1;
    else cout << answer;
    
    return 0;
}
