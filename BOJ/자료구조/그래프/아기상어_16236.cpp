#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct P{
    int r, c;
    int time;
};

struct Shark{
    int r, c;
    int Size = 2;
    int eat = 0;
};

int N, seconds = 0;
int Map[21][21];
int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};
bool is_found = true;

Shark baby;


void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Map[i][j];
            if(Map[i][j] == 9){
                baby.r = i;
                baby.c = j;
                Map[i][j] = 0;
            }
        }
    }
}

P find_eating(vector<P>& can_eat){
    P near = can_eat[0];
    for(int i = 1; i < can_eat.size(); i++){
        if(can_eat[i].time < near.time) near = can_eat[i];
        else if(can_eat[i].time == near.time){
                
            if(can_eat[i].r < near.r) near = can_eat[i];
            else if(can_eat[i].r == near.r){
                
                if(can_eat[i].c < near.c) near = can_eat[i];
            }
        }
    }
    return near;
}

void find_feed(){
    
    queue<P> que;
    vector<P> can_eat;
    
    bool visited[21][21];
    memset(visited, 0, sizeof(visited));
    visited[baby.r][baby.c] = true;
    
    que.push({baby.r, baby.c, 0});
    
    while(!que.empty()){
        int nowr = que.front().r;
        int nowc = que.front().c;
        int nowt = que.front().time;
        
        que.pop();
        
        for(int i = 0; i < 4; i++){
            int nr = nowr + dr[i];
            int nc = nowc + dc[i];
            if(!visited[nr][nc] && Map[nr][nc] <= baby.Size &&\
                nr >= 0 && nr < N && nc >= 0 && nc < N){
                //���� �� �ִ� ���� �߰�
                if(Map[nr][nc] < baby.Size && Map[nr][nc] != 0){
                    can_eat.push_back({nr, nc, nowt+1});
                }
                // nr, nc�� ���� �湮ó���� ����� �ϴµ� 
                // visited[nowr][nowc] �ڵ�� nowr, nowc�� ���� �湮ó���� �ߺ����� ���༭
                // �ʿ���� �����͵��� ���̴� ���� �޸� �ʰ��� �߻�����
                // BFS que�޸� �����°� �����ϱ�!
                visited[nr][nc] = true;
                que.push({nr, nc, nowt+1});
            }
        }
    }
    
    if(can_eat.empty()) is_found = false;
    else{
        P result = find_eating(can_eat);
        baby.r = result.r;
        baby.c = result.c;
        baby.eat++;
        Map[baby.r][baby.c] = 0;
        seconds += (result.time);
        if(baby.eat == baby.Size){
            baby.Size++;
            baby.eat = 0;
        }
    }
    
    return;
}

void solve(){
    // ���̸� �� ã�� ������ loop
    while(is_found){
        find_feed();
    }
    cout << seconds;
}

int main(){
    input();
    solve();
    
    return 0;
}
