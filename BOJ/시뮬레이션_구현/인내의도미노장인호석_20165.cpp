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

struct attack{
    int r, c, dir;
};

int N, M, R, score;
int Map[101][101];
int TMap[101][101];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

vector<attack> Attacker;
vector<pii > Defender;

void input(){
    cin >> N >> M >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Map[i][j];
            TMap[i][j] = Map[i][j];
        }
    }
    int a, b;
    char c;
    for(int i = 0; i < R*2; i++){
        if(i % 2 == 0){
            cin >> a >> b >> c;
            switch (c){
            case 'E':
                Attacker.push_back({a-1, b-1, 0});
                break;
            case 'W':
                Attacker.push_back({a-1, b-1, 1});
                break;
            case 'S':
                Attacker.push_back({a-1, b-1, 2});
                break;
            case 'N':
                Attacker.push_back({a-1, b-1, 3});
                break;
            default:
                break;
            }
        }
        else{
            cin >> a >> b;
            Defender.push_back({a-1, b-1});
        }
    }
}

void crash_domino(int r, int c, int dir){
    int last = Map[r][c];
    switch (dir){
    case 0:
        while(c < M && last){
            last = max(last, Map[r][c]);
            if(Map[r][c]){
                Map[r][c] = 0;
                score++;
            }
            c++;
            last--;
        }
        break;
    case 1:
        while(c >= 0 && last){
            last = max(last, Map[r][c]);
            if(Map[r][c]){
                Map[r][c] = 0;
                score++;
            }
            c--;
            last--;
        }
        break;
    case 2:
        while(r < N && last){
            last = max(last, Map[r][c]);
            if(Map[r][c]){
                Map[r][c] = 0;
                score++;
            }
            r++;
            last--;
        }
        break;
    case 3:
        while(r >= 0 && last){
            last = max(last, Map[r][c]);
            if(Map[r][c]){
                Map[r][c] = 0;
                score++;
            }
            r--;
            last--;
        }
        break;
    
    default:
        break;
    }
}

inline void raise_domino(int r, int c){
    Map[r][c] = TMap[r][c];
}

void show(){
    
    cout << score << "\n";
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            if(!Map[r][c]) cout << 'F' << " ";
            else cout << 'S' << " ";
        }
        cout << "\n";
    }
}

void solve(){
    for(int i = 0; i < R; i++){
        crash_domino(Attacker[i].r, Attacker[i].c, Attacker[i].dir);
        raise_domino(Defender[i].first, Defender[i].second);
    }
    
    show();
}

int main(){
    input();
    solve();
    
    return 0;
}
