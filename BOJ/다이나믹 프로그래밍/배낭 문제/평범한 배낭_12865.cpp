#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, K;

struct T{
    int weight, value;
};

vector<T> Prod;

// dp[���� ������ ��ȣ][�ִ� �賶 ����] = �賶�� �ִ� ���԰� j�϶��� �ִ� ��ġ
int dp[101][100001];

inline void input(){
    int w, v;
    cin >> N >> K;
    Prod.resize(N+1);
    Prod[0] = {0, 0};
    for(int i = 1; i <= N; i++){
        // ���Կ� ��ġ�� ������� �Է�
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
            // ���� ������ ���԰� �ִ� �賶���Ժ��� ���ſ�� ������ �ִ� ��ġ ����
            if(w < now_weight) dp[i][w] = max(dp[i][w], dp[i-1][w]);
            
            // ���� ������ ���԰� �ִ� �賶���Ժ��� ������� ���� �� ����.
            // �� �� max(������ ���� �ʴ°��, ������ ��� ���) �� �ִ�
            // ������ ��� ��쿡 dp[i-1][w-weight]�� ���� ������ ���� ������ ���԰�
            // w�� ���� �Ǿ��� ������ (���� ���Ǳ����� �ִ�)dp[i-1]���� 
            // ���� ������ ���԰� ���� ���Ե��� ���� �ִ밡ġ([w-weight])�� ���� ������ ��ġ�� ���ؼ� ��
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
