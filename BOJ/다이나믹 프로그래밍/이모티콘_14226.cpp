#include <iostream>
#include <queue>
using namespace std;

struct P{
    int img_num;
    int clipBoard;
    int time;
};

int S;
bool dp[2001][2001];

int BFS(){
    queue<P> que;
    que.push({1, 0, 0});
    dp[1][0] = true;
    
    while(!que.empty()){
        int img = que.front().img_num;
        int clip = que.front().clipBoard;
        int t = que.front().time;
        que.pop();
        
        if(img == S) return t;
        
        
        if(img > 0 && img < 2001){
            // img를 복사하는 경우
            if(!dp[img][img]){
                dp[img][img] = true;
                que.push({img, img, t+1});
            }
            // img를 삭제하는 경우
            if(!dp[img-1][clip]){
                dp[img-1][clip] = true;
                que.push({img-1, clip, t+1});
            }
        }
        if(clip > 0 && clip + img < 2001){
            // 붙여넣기 하는 경우
            if(!dp[img+clip][clip]){
                dp[img+clip][clip] = true;
                que.push({img+clip, clip, t+1});
            }
        }
        
    }
}

inline void solve(){
    cout << BFS();
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> S;
    solve();
    
    return 0;
}
