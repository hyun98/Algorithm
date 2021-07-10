#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N, K, S;
vector<int> Graph[401];
int order[401][401];
pii ires[50001];

void input(){
    cin >> N >> K;
    int a, b;
    for(int i = 0; i < K; i++){
        cin >> a >> b;
        Graph[a].push_back(b);
        order[a][b] = 1;
    }
    
    cin >> S;
    for(int i = 0; i < S; i++){
        cin >> a >> b;
        ires[i] = {a, b};
    }
}

void Folyd(){
    for(int k = 1; k <= N; k++){
        for(int r = 1; r <= N; r++){
            for(int c = 1; c <= N; c++){
                if(order[r][k] && order[k][c]){
                    order[r][c] = 1;
                }
            }
        }
    }
    for(int i = 0; i < S; i++){
        int now = order[ires[i].first][ires[i].second];
        int rev_now = order[ires[i].second][ires[i].first];
        if(now) cout << -now << "\n";
        else if(rev_now) cout << rev_now << "\n";
        else cout << 0 << "\n";
    }
}

int main(){
    fasti
    input();
    Folyd();
    
    return 0;
}
