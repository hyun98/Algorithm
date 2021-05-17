//재귀로 풀기 실패
#include <iostream>

using namespace std;

int cache[301], stair[301];

int solve(int x){
    if(x == 0) return cache[0] = stair[0];
    if(x == 1) return cache[0] = stair[1] + stair[0];
    if(x == 2) return cache[0] = max(stair[0] + stair[2], stair[1] + stair[2]);
    if(cache[x] != 0) return cache[x];
    // 이전 계단을 밟지 않은 경우, 밟은 경우
    int result = max(solve(x-2) + stair[x], solve(x-3) + stair[x-1] + stair[x]);
    
    return cache[x] = result;
}

int main(){
    int stair_num;
    cin >> stair_num;
    for(int i = 0; i < stair_num; i++){
        cin >> stair[i];
    }
    cout << solve(stair_num);
    
    return 0;
}
