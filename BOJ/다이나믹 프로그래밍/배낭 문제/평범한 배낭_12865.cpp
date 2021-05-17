#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, K;

struct T{
    int weight, value;
};

vector<T> Prod;

// dp[현재 물건의 번호][최대 배낭 무게] = 배낭의 최대 무게가 j일때의 최대 가치
int dp[101][100001];

inline void input(){
    int w, v;
    cin >> N >> K;
    Prod.resize(N+1);
    Prod[0] = {0, 0};
    for(int i = 1; i <= N; i++){
        // 무게와 가치를 순서대로 입력
        cin >> w >> v;
        Prod[i] = {w, v};
    }
    memset(dp, 0, sizeof(dp));
}

void solve(){
    
    for(int i = 1; i <= N; i++){
        int now_val = Prod[i].value;
        int now_weight = Prod[i].weight;
        for(int w = 0; w <= K; w++){
            // 현재 물건의 무게가 최대 배낭무게보다 무거우면 기존의 최대 가치 유지
            if(w < now_weight) dp[i][w] = max(dp[i][w], dp[i-1][w]);
            
            // 현재 물건의 무게가 최대 배낭무게보다 가벼우면 담을 수 있음.
            // 이 때 max(물건을 담지 않는경우, 물건을 담는 경우) 중 최댓값
            // 물건을 담는 경우에 dp[i-1][w-weight]를 해준 이유는 현재 물건의 무게가
            // w에 포함 되었기 때문에 (이전 물건까지의 최댓값)dp[i-1]에서 
            // 현재 물건의 무게가 아직 포함되지 않은 최대가치([w-weight])에 현재 물건의 가치를 더해서 비교
            else dp[i][w] = max(dp[i-1][w], dp[i-1][w-now_weight] + now_val);
        }
    }
    cout << dp[N][K];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    
    return 0;
}
