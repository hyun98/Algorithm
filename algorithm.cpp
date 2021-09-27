#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#define pii pair<int, int>

using namespace std;

int N;
vector<pii> points;
double result;
bool visited[21];

double vec_sum(){
    pii vec = {0, 0};
    for(int i = 0; i < N; i++){
        if(visited[i]){
            vec.first -= points[i].first;
            vec.second -= points[i].second;
        }
        else{
            vec.first += points[i].first;
            vec.second += points[i].second;
        }
    }
    
    return sqrt(pow(vec.first, 2) + pow(vec.second, 2));
}

void dfs(int now, int cnt){
    if(cnt == N/2){
        result = min(result, vec_sum());
        return;
    } 
    
    for(int i = now; i < N; i++){
        visited[i] = true;
        dfs(i+1, cnt+1);
        visited[i] = false;
    }
}

void solve(){
    dfs(0, 0);
    printf("%.7lf\n", result);
}

void input(){
    int a, b;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        points.push_back({a, b});
    }
}

int main(){
    int test;
    cin >> test;
    while(test--){
        memset(visited, 0, sizeof(visited));
        points.clear();
        result = 1e9+7;
    
        input();
        solve();
    }
    
    return 0;
}

