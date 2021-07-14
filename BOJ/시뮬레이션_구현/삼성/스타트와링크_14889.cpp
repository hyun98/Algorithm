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

int N;
int Stat[21][21];
int statSum, result = INF;
bool visited[21];

void input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> Stat[i][j];
            statSum += Stat[i][j];
        }
    }
}

void backtracking(vector<int> &save, int now, int cnt){
    if(cnt == N/2){
        int tempsum1 = 0, tempsum2 = 0;
        vector<int> another;
        for(int i = 1; i <= N; i++){
            if(!visited[i]){
                another.push_back(i);
            }
        }
        
        for(int i = 0; i < N/2; i++){
            for(int j = 0; j < N/2; j++){
                if(i == j) continue;
                tempsum1 += Stat[save[i]][save[j]];
                tempsum2 += Stat[another[i]][another[j]];
            }
        }
        int tempmin = abs(tempsum1 - tempsum2);
        
        result = min(result, tempmin);
        
        return;
    }
    
    for(int i = now; i <= N; i++){
        if(visited[i]) continue;
        visited[i] = true;
        save.push_back(i);
        backtracking(save, i+1, cnt+1);
        save.pop_back();
        visited[i] = false;
    }
}

void solve(){
    vector<int> save;
    save.push_back(1);
    visited[1] = true;
    
    backtracking(save, 2, 1);
    
    cout << result;
}

int main(){
    input();
    solve();
    
    return 0;
}
