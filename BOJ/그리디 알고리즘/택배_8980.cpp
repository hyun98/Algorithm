#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

vector< pii > deli[2001];
int truck[2001];

int N, M, C;
int truck_capacity, result;

void input(){
    cin >> N >> C >> M;
    int u, v, n;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> n;
        deli[u].push_back({v, n});
    }
    
    // 배송지 번호 순으로 오름차순 정렬
    for(int i = 1; i <= N; i++){
        sort(deli[i].begin(), deli[i].end());
    }
}

void solve(){
    for(int i = 1; i <= N; i++){
        // i번째 마을에 짐 배달 완료
        result += truck[i];
        truck_capacity -= truck[i];
        
//        cout << "현재 마을 : " << i << "\n";
//        cout << "now capacity : " << truck_capacity << "\n";
//        cout << "now result : " << result << "\n=========\n";
        
        // i마을의 배달 정보 확인
        for(auto &w : deli[i]){

            int box_num = w.second;
            int dest = w.first;
            
            // 전부 트럭에 실을 수 있으면
            if(box_num + truck_capacity <= C){
                truck_capacity += box_num;   // 트럭의 용량 채워짐
                truck[dest] += box_num;  // 트럭이 도착지에서 내려야 할 
            }
            else{   // 트럭에 일부만 실어야 할 경우
                // 비워야 할 용량
                int cd = box_num - (C - truck_capacity);
                
                // 실을 짐의 도착지보다 먼 곳의 짐 빼기
                for(int k = N; k >= dest+1; k--){
                    if(truck[k] >= cd){
                        truck[k] -= cd;
                        cd = 0;
                        break;
                    }
                    else{
                        cd -= truck[k];
                        truck[k] = 0;
                    }
                }
                truck_capacity = C;
                truck[dest] += (box_num - cd);
            }
        }
    }
    
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    solve();
    
    return 0;
}
