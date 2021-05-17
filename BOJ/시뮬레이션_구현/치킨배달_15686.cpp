#include <iostream>
#include <vector>

using namespace std;

struct P{
    int row, col;
};

int N, M;
vector<P> house, chicken;
int result[51][51];     //ġŲ���鿡 ���� ������ �ִܰŸ��� �����ϴ� �迭
int citysum = 99999999;

void input(){
    int temp;
    cin >> N >> M;
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            cin >> temp;
            switch(temp){
                case 1: house.push_back({r, c}); break;
                case 2: chicken.push_back({r, c}); break;
                default: break;
            }
        }
    }
}

bool visited[15] = {false, };
vector< vector<int> > combi;
vector<int> temp;

//M���� ġŲ���� ��󳻴� �Լ�  (nCm) ����
//python�� combination �� ����!
void make_combination(int now){
    if(temp.size() == M){
        combi.push_back(temp);
        return;
    }
    
    for(int i = now; i < chicken.size(); i++){
        if(!visited[i]){
            temp.push_back(i);
            visited[i] = true;
            make_combination(i+1);
            visited[i] = false;
            temp.pop_back();
        }
    }
}

inline void reset_res(){
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            result[r][c] = 99999;
        }
    }
}
// ���� ����� ġŲ������ �Ÿ��� ���� result�迭�� ������
// �ݺ����� ���� �ִܰŸ����� ���� ����
inline void city(){
    int sum = 0;
    for(int i = 0; i < house.size(); i++){
        sum += result[house[i].row][house[i].col];
    }
    citysum = min(citysum, sum);
}
// ġŲ���� ��ǥ�� ���� �������� �Ÿ��� ���Ѵ�
inline void check(int r, int c){
    for(int i = 0; i < house.size(); i++){
        int dist = abs(r-house[i].row) + abs(c-house[i].col);
        // ���� ���ο� ġŲ���� �Ÿ��� ���� ġŲ������ �Ÿ����� ������ ����� ����
        result[house[i].row][house[i].col] = min(dist, result[house[i].row][house[i].col]);
    }
}

void solve(){
    for(int i = 0; i < combi.size(); i++){
        reset_res();
        for(int j = 0; j < combi[i].size(); j++){
            check(chicken[combi[i][j]].row, chicken[combi[i][j]].col);
        }
        city();
    }
    
    cout << citysum;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    make_combination(0);
    solve();
    
    return 0;
}
