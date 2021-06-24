#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Eucircuit;
int N, adj[1001][1001], degree[1001];
bool visited[1001];

void findEuler(int now){
    visited[now] = true;
    for(int i = 1; i <= N; i++){
        if(!adj[now][i]) continue;
        while(adj[now][i] > 0){
            adj[now][i]--;
            adj[i][now]--;
            findEuler(i);
        }
    }
    Eucircuit.push_back(now);
}

bool input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> adj[i][j];
            degree[i] += adj[i][j];
        }
        if(degree[i] % 2) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if(!input()){
        cout << -1;
        return 0;
    }
    
    findEuler(1);
    reverse(Eucircuit.begin(), Eucircuit.end());
    
    for(auto &w : Eucircuit){
        cout << w << " ";
    }
    
    return 0;
}
