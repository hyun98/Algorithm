// 한계 도전 프로젝트 #1
// BOJ 2618 경찰차 Platinum V
// 다이나믹 프로그래밍
// 2021.05.11

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct P{
    int x, y;
};

vector<P> command;
vector<int> result;

int dp[1010][1010];
int N, W;

inline int dist(P src, P dst){
    return abs(src.x - dst.x) + abs(src.y - dst.y);
}

int solve(int car1, int car2){
    int &ret = dp[car1][car2];
    if(ret != -1) return ret;
    
    int next_case = max(car1, car2) + 1;
    if(next_case > W) return ret = 0;
    
    // 1번 차에서 다음 사건으로 가는 거리, 2번 차에서 다음 사건으로 가는 거리
    int dist1, dist2;
    
    // 시작점에 있는경우와 아닌경우
    if(car1 == 0) dist1 = dist({1, 1}, command[next_case]);
    else dist1 = dist(command[car1], command[next_case]);
    
    if(car2 == 0) dist2 = dist({N, N}, command[next_case]);
    else dist2 = dist(command[car2], command[next_case]);
    
    int take_car1 = solve(next_case, car2) + dist1;
    int take_car2 = solve(car1, next_case) + dist2;
    // 1번 차가 현재 사건을 맡고 다음으로 가는경우, 2번 차가 현재 사건을 맡고 다음으로 가는경우 중 최솟값
    ret = min(take_car1, take_car2);
    
    return ret;
}

void backtracing(int car1, int car2){
    
    int next_case = max(car1, car2) + 1;
    if(next_case > W) return;
    
    int dist1, dist2;
    
    if(car1 == 0) dist1 = dist({1, 1}, command[next_case]);
    else dist1 = dist(command[car1], command[next_case]);
    if(car2 == 0) dist2 = dist({N, N}, command[next_case]);
    else dist2 = dist(command[car2], command[next_case]);
    
    int take_car1 = dp[next_case][car2] + dist1;
    int take_car2 = dp[car1][next_case] + dist2;
    
    // 현재 상태에서 움직였을 때 더 짧은 거리를 이동하는 쪽으로 backtracing을 해준다
    if(take_car1 < take_car2){
        result.push_back(1);
        backtracing(next_case, car2);
    }
    else{
        result.push_back(2);
        backtracing(car1, next_case);
    }
    
}

void input(){
    int a, b;
    P in;
    cin >> N >> W;
    command.resize(W+1);
    for(int i = 1; i <= W; i++){
        cin >> a >> b;
        in.x = a;
        in.y = b;
        command[i] = in;
    }
    memset(dp, -1, sizeof(dp));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    cout << solve(0, 0) << "\n";
    backtracing(0, 0);
    
    for(int i = 0; i < W; i++){
        cout << result[i] << "\n";
    }
    return 0;
}