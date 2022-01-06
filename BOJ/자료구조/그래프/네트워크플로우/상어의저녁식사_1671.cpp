#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 2e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

struct Shark{
    int vol, speed, iq;
    
    bool operator==(Shark &a){
        return (vol == a.vol && speed == a.speed && iq == a.iq);
    }
    bool operator>=(Shark &a){
        return (vol >= a.vol && speed >= a.speed && iq >= a.iq);
    }
};

int N;
int capacity[110][110], flow[110][110];
vector<int> adj[110];
vector<Shark> sh;


bool cmp(Shark &a, Shark &b){
    if(a.vol < b.vol && a.speed < b.speed && a.iq < b.iq) return true;
    else return false;
}

void input(){
    cin >> N;
    int vol, speed, iq;
    for(int i = 0; i < N; i++){
        cin >> vol >> speed >> iq;
        sh.push_back({vol, speed, iq});
    }
    
    // sort(sh.begin(), sh.end(), cmp);
    
    for(int k = 2; k < N+2; k++){
        adj[k].push_back(0);
        adj[0].push_back(k);
        capacity[0][k] = 2;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            if(sh[i] == sh[j] && i > j) continue;
            if(sh[i] >= sh[j]){
                adj[i+2].push_back(2+N+j);
                adj[2+N+j].push_back(i+2);
                capacity[2+i][2+N+j] = 1;
            }
        }
    }
    for(int i = 0; i < N; i++){
        adj[1].push_back(2+N+i);
        adj[2+N+i].push_back(1);
        capacity[2+N+i][1] = 1;
    }
}

void solve(){
    int total_flow = 0;
    
    while(true){
        vector<int> prev(110, -1);
        queue<int> que;
        que.push(0);
        prev[0] = 0;
        
        while(!que.empty() && prev[1] == -1){
            int now = que.front();
            que.pop();
            
            for(int i = 0; i < adj[now].size(); i++){
                int next = adj[now][i];
                if(capacity[now][next] - flow[now][next] > 0 && prev[next] == -1){
                    prev[next] = now;
                    que.push(next);
                }
            }
        }
        
        if(prev[1] == -1) break;
        
        int amount = INF;
        for(int p = 1; p != 0; p = prev[p]){
            amount = min(amount, capacity[prev[p]][p] - flow[prev[p]][p]);
        }
        for(int p = 1; p != 0; p = prev[p]){
            flow[prev[p]][p] += amount;
            flow[p][prev[p]] -= amount;
        }
        
        total_flow += amount;
    }
    
    cout << N - total_flow;
}

int main(){
    input();
    solve();
    
    return 0;
}
