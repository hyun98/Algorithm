#include <bits/stdc++.h>

using namespace std;

int N, student[100001], result;
bool visited[100001];   
bool check[100001]; // 인덱스에 해당하는 학생이 팀을 이루었는지 확인하는 배열

void makeUnion(int st, int p, int& res){
    res++;
    if(student[p] == st) return;
    else makeUnion(st, student[p], res);
}

void dfs(int now, int& res){
    visited[now] = true;
    int next = student[now];
    
    if(!visited[next]) dfs(next, res);  // 만약 다음 학생을 방문하지 않았다면 go
    else if(!check[next]){      // next에 방문을 했고, 아직 팀을 이루는지 확인하지 못했다면 
        // next가 사이클의 시작이 되고, 자기 자신에게 돌아올 때까지 res++
        for(int i = next; i != now; i = student[i]){
            res++;
        }
        res++;  // 자기자신
        // makeUnion(next, next, res);
    }
    // now가 팀을 이루는지 확인했으므로 true
    check[now] = true;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        memset(visited, false, sizeof(visited));
        memset(check, false, sizeof(check));
        int sn, res = 0;    // res : 사이클을 이루는 학생 수
        cin >> sn;
        for(int i = 1; i <= sn; i++){
            cin >> student[i];
        }
        
        for(int i = 1; i <= sn; i++){
            if(!visited[i]) dfs(i, res);
        }
        cout << sn - res << "\n";
    }
    return 0;
}
