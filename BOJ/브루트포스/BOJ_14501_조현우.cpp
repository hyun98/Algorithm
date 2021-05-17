#include <iostream>
using namespace std;

int N, Ti[16], Pi[16], dp[16] = {0, };

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> Ti[i] >> Pi[i];
    }
}

// O(N^2)
void solve1(){
    int result = 0;
    for(int i = 0; i < N; i++){
        // Ti를 돌면서 Ti[i]와 i일을 더했을 때 N일 보다 크다면 일을 할 수 없으므로 넘어간다
        if(Ti[i] + i > N) continue;
        //처음 dp[i]에 접근하면 i일 일때 일한 수익으로 초기화
        dp[i] = Pi[i];
        
        // 처음부터 i일 직전까지 탐색
        for(int j = 0; j < i; j++){
            // j일 일때 그날의 일을 하고 마무리 하는 날이, i일을 넘어가면 i일의 일을 할 수 없으므로 넘어간다
            if(j + Ti[j] > i) continue;
            // 그렇지 않다면 현재 dp값과 (j일 까지 일한 최대 수익+i일 수익)중 큰값으로 dp값 교체
            dp[i] = max(dp[i], Pi[i] + dp[j]);
        }
        // 결과 값 갱신
        result = max(dp[i], result);
    }
    
    cout << result;
}

// top-down style O(N^2)
int solve2(int day){
    if(day + Ti[day] > N) return 0;
    if(day + Ti[day] == N) return Pi[day];
    
    for(int i = day + Ti[day]; i <= N; i++){
        dp[day] = max(dp[day], solve2(i) + Pi[day]);
    }
    return dp[day];
}

// dynamic programming bottom-up style O(N)
void solve3(){
    int result = 0;
    //뒤에서부터 탐색 
    for(int i = N-1; i >= 0; i--){
        // next : 다음 날짜
        int next = i + Ti[i];
        if(next > N){
            dp[i] = dp[i+1];
        }
        // next일에 일을 할지, 말지 결정
        else{
            dp[i] = max(dp[i+1], dp[next] + Pi[i]);
        }
    }
    cout << dp[0];
}

int main(){
    input();
    int result = 0;
//    for(int i = 0; i < N; i++){
//        result = max(result, solve2(i));
//    }
//    
//    cout << result;
    
    solve3();
    return 0;
}
