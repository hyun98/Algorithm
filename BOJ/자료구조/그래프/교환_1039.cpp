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

struct info{
    string num;
    int kcnt;
};

string number;
int N, M, K, ans;
int check[1000001][11];

void input(){
    cin >> number >> K;
    N = stoi(number);
    ans = N;
    M = number.size();
    
    memset(check, -1, sizeof(check));
}

int dfs(string now, int kcnt){
    if(kcnt == K) return stoi(now);
    int &ret = check[stoi(now)][kcnt];
    if(ret != -1) return ret;
    
    for(int i = 0; i < M; i++){
        for(int j = i+1; j < M; j++){
            string temp = now;
            swap(temp[i], temp[j]);
            if(temp[0] == '0') continue;
            
            ret = max(ret, dfs(temp, kcnt+1));
        }
    }
    
    return ret;
}

int bfs(){
    string temp;
    int tempi;
    
    queue<info> que;
    que.push({number, 0});
    check[N][0] = 1;
    
    while(!que.empty()){
        string now = que.front().num;
        int now_cnt = que.front().kcnt;
        que.pop();
        
        if(now_cnt == K){
            ans = max(ans, stoi(now));
            continue;
        }
        
        for(int i = 0; i < M-1; i++){
            for(int j = i+1; j < M; j++){
                string temp = now;
                swap(temp[i], temp[j]);
                if(temp[0] == '0') continue;
                tempi = stoi(temp);
                if(check[tempi][now_cnt+1] != -1) continue;
                check[tempi][now_cnt+1] = 1;
                que.push({temp, now_cnt+1});
            }
        }
    }
    return ans;
}

int main(){
    input();
    if(M == 1 || (M == 2 && number[1] == '0')) cout << -1;
    else cout << dfs(number, 0);
    
    return 0;
}

