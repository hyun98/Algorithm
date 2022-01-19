#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

struct State{
    pii st;
    int cnt;
};

int A, B, C, D;
map<pii, int> visited;

void input(){
    cin >> A >> B >> C >> D;
}

void bfs(){
    int answer = INF;
    
    pii start = {0, 0};
    queue<State> que;
    que.push({start, 0});
    visited[start] = 1;
    
    while(!que.empty()){
        pii now = que.front().st;
        int now_cnt = que.front().cnt;
        que.pop();
        pii _next;
        
        if(now.first == C && now.second == D){
            answer = min(answer, now_cnt);
        }
        
        // A물통을 가득 채우는 경우
        _next = {A, now.second};
        if(!visited[_next]){
            visited[_next] = 1;
            que.push({_next, now_cnt+1});
        }
        
        // B물통을 가득 채우는 경우
        _next = {now.first, B};
        if(!visited[_next]){
            visited[_next] = 1;
            que.push({_next, now_cnt+1});
        }
        
        // A를 모두 버리는 경우
        _next = {0, now.second};
        if(!visited[_next]){
            visited[_next] = 1;
            que.push({_next, now_cnt+1});
        }
        
        // B를 모두 버리는 경우
        _next = {now.first, 0};
        if(!visited[_next]){
            visited[_next] = 1;
            que.push({_next, now_cnt+1});
        }
        
        // A -> B로 이동
        int b_left = B - now.second;
        if(now.first >= b_left) _next = {now.first - b_left, B};
        else _next = {0, now.first + now.second};
        if(!visited[_next]){
            visited[_next] = 1;
            que.push({_next, now_cnt+1});
        }
        
        // B -> A로 이동
        int a_left = A - now.first;
        if(now.second >= a_left) _next = {A, now.second - a_left};
        else _next = {now.first + now.second, 0};
        if(!visited[_next]){
            visited[_next] = 1;
            que.push({_next, now_cnt+1});
        }
    }
    
    if(answer == INF) cout << -1;
    else cout << answer;
}

void solve(){
    bfs();
}

int main(){
    input();
    solve();
    
    return 0;
}
