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
    
    // ����� ��ȣ ������ �������� ����
    for(int i = 1; i <= N; i++){
        sort(deli[i].begin(), deli[i].end());
    }
}

void solve(){
    for(int i = 1; i <= N; i++){
        // i��° ������ �� ��� �Ϸ�
        result += truck[i];
        truck_capacity -= truck[i];
        
//        cout << "���� ���� : " << i << "\n";
//        cout << "now capacity : " << truck_capacity << "\n";
//        cout << "now result : " << result << "\n=========\n";
        
        // i������ ��� ���� Ȯ��
        for(auto &w : deli[i]){

            int box_num = w.second;
            int dest = w.first;
            
            // ���� Ʈ���� ���� �� ������
            if(box_num + truck_capacity <= C){
                truck_capacity += box_num;   // Ʈ���� �뷮 ä����
                truck[dest] += box_num;  // Ʈ���� ���������� ������ �� 
            }
            else{   // Ʈ���� �Ϻθ� �Ǿ�� �� ���
                // ����� �� �뷮
                int cd = box_num - (C - truck_capacity);
                
                // ���� ���� ���������� �� ���� �� ����
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
