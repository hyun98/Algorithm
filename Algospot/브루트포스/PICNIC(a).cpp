#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;
vector< vector<bool> > arebudy;
vector<bool> visited(10, false);

void solve(){
    int first = -1;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            first = i;
            break;
        }
    }

    if(first == -1){
        ans += 1;
        return;
    }
    for(int i = first+1; i < n; i++){
        if(!visited[i] && arebudy[first][i]){
            visited[i] = visited[first] = true;
            solve();
            visited[i] = visited[first] = false;
        }
    }
    return;
}

void make(){
    int a, b;
    //양방향 그래프로 친구관계를 나타낼 수 있다
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        arebudy[a][b] = true;
        arebudy[b][a] = true;
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        arebudy.resize(n+1, vector<bool>(n+1, false));
        make();
        ans = 0;
        solve();
        cout << ans << "\n";
        arebudy.clear();
    }

    return 0;
}
//3
//2 1
//0 1
//4 6
//0 1 1 2 2 3 3 0 0 2 1 3
//6 10
//0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
