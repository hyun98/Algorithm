#include <string>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9+7
#define pii pair<int, int>

/**
 플로이드와샬 풀이
**/

int floyd_adj[201][201];

bool reachable(int a, int b){
    // a -> b
    if(floyd_adj[a][b] == INF) return false;
    return true;
}

int floyd_solusion(int &n, int &s, int &a, int &b, vector<vector<int>> &fares){
    int answer = INF;
    
    for(int i = 0; i < 201; i++){
        for(int j = 0; j < 201; j++){
            floyd_adj[i][j] = INF;
            if(i == j) floyd_adj[i][j] = 0;
        }
    }
    
    for(auto &fare : fares){
        int src = fare[0];
        int dst = fare[1];
        int cost = fare[2];
        floyd_adj[src][dst] = cost;
        floyd_adj[dst][src] = cost;
    }
    
    
    for(int via = 1; via <= n; via++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(!reachable(i, via) || !reachable(via, j)) continue;
                floyd_adj[i][j] = min(floyd_adj[i][j], floyd_adj[i][via] + floyd_adj[via][j]);
            }
        }
    }
    
    for(int cross = 1; cross <= n; cross++){
        if(!reachable(s, cross) || !reachable(cross, a) || !reachable(cross, b)) continue;
        int temp = floyd_adj[s][cross] + floyd_adj[cross][a] + floyd_adj[cross][b];
        answer = min(answer, temp);
    }
    
    return answer;
}


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    answer = floyd_solusion(n, s, a, b, fares);
    
    return answer;
}