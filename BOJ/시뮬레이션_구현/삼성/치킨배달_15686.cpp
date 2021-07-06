#include <iostream>
#include <vector>

using namespace std;

struct P{
    int row, col;
};

int N, M;
vector<P> house, chicken;
int result[51][51];     //치킨집들에 대한 집들의 최단거리를 저장하는 배열
int citysum = 99999999;

void input(){
    int temp;
    cin >> N >> M;
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            cin >> temp;
            switch(temp){
                case 1: house.push_back({r, c}); break;
                case 2: chicken.push_back({r, c}); break;
                default: break;
            }
        }
    }
}

bool visited[15] = {false, };
vector< vector<int> > combi;
vector<int> temp;

//M개의 치킨집을 골라내는 함수  (nCm) 조합
//python의 combination 과 같음!
void make_combination(int now){
    if(temp.size() == M){
        combi.push_back(temp);
        return;
    }
    
    for(int i = now; i < chicken.size(); i++){
        if(!visited[i]){
            temp.push_back(i);
            visited[i] = true;
            make_combination(i+1);
            visited[i] = false;
            temp.pop_back();
        }
    }
}

inline void reset_res(){
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            result[r][c] = 99999;
        }
    }
}
// 가장 가까운 치킨집과의 거리만 남은 result배열을 가지고
// 반복문을 통해 최단거리들의 합을 구함
inline void city(){
    int sum = 0;
    for(int i = 0; i < house.size(); i++){
        sum += result[house[i].row][house[i].col];
    }
    citysum = min(citysum, sum);
}
// 치킨집의 좌표로 부터 집까지의 거리를 구한다
inline void check(int r, int c){
    for(int i = 0; i < house.size(); i++){
        int dist = abs(r-house[i].row) + abs(c-house[i].col);
        // 집과 새로운 치킨집의 거리가 기존 치킨집과의 거리보다 가까우면 결과를 갱신
        result[house[i].row][house[i].col] = min(dist, result[house[i].row][house[i].col]);
    }
}

void solve(){
    for(int i = 0; i < combi.size(); i++){
        reset_res();
        for(int j = 0; j < combi[i].size(); j++){
            check(chicken[combi[i][j]].row, chicken[combi[i][j]].col);
        }
        city();
    }
    
    cout << citysum;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    make_combination(0);
    solve();
    
    return 0;
}
