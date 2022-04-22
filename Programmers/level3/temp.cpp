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


vector<pii> pairTile[27];


void moveNext(int &s, int &e){
    if(s < e) s++;
    else s--;
}

int findRoute(int alpha, vector<string> &board){
    pii S = pairTile[alpha][0];
    pii E = pairTile[alpha][1];
    
    // route 1 : row first
    bool route1 = true;
    while(S.first != E.first){
        if(!route1) break;
        moveNext(S.first, E.first);
        if(board[S.first][S.second] == char(48 + alpha)) return true;
        if(board[S.first][S.second] != '.') route1 = false;
    }
    while(S.second != E.second){
        if(!route1) break;
        moveNext(S.second, E.second);
        if(board[S.first][S.second] == char(48 + alpha)) return true;
        if(board[S.first][S.second] != '.') route1 = false;
    }
    
    S = pairTile[alpha][0];
    E = pairTile[alpha][1];
    // route 2 : col first
    bool route2 = true;
    while(S.second != E.second){
        if(!route2) break;
        moveNext(S.second, E.second);
        if(board[S.first][S.second] == char(48 + alpha)) return true;
        if(board[S.first][S.second] != '.') route1 = false;
    }
    while(S.first != E.first){
        if(!route2) break;
        moveNext(S.first, E.first);
        if(board[S.first][S.second] == char(48 + alpha)) return true;
        if(board[S.first][S.second] != '.') route1 = false;
    }
    
    if(route1 || route2) return true;
    else return false;
}

bool canDelete(int alpha, vector<string> &board){
    if(pairTile[alpha].empty()) return false;
    
    return findRoute(alpha, board);
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> &bb) {
    string answer = "";
    vector<string> board;
    
    
    for(int i = 0; i < 27; i++){
        pairTile[i].clear();
    }
    
    for(int i = 0; i < bb.size(); i++){
        for(int j = 0; j < bb[i].size(); j++){
            char alphabet = bb[i][j];
            if(alphabet == '.' || alphabet == '*') continue;
            int idx = alphabet - 'A';
            pairTile[idx].push_back({i, j});
        }
    }
    
    bool prev = false, is_fail = false;
    
    vector<char> tempc;
    while(true){
        tempc.clear();
        for(int i = 0; i < 26; i++){
            if(pairTile[i].empty()) continue;
            if(findRoute(i, board)){
                tempc.push_back(board[pairTile[i][0].first][pairTile[i][0].second]);
            }
        }
        
        if(tempc.empty()){
            if(!prev) break;
            prev = false;
        }
        else{
            sort(tempc.begin(), tempc.end());
            for(auto &w: tempc){
                answer += w;
            }
            cout << answer << '\n';
        }
    }
    
    for(int i = 0; i < 26; i++){
        if(pairTile[i].empty()) continue;
        is_fail = true;
    }
    
    if(is_fail){
        answer = "IMPOSSIBLE";
    }
    
    return answer;
}

int main(){
    int m = 4;
    int n = 4;
    vector<string> board = {".ZI.", "M.**", "MZU.", ".IU."};
    
    cout << solution(m, n, board);
    
    return 0;
}
