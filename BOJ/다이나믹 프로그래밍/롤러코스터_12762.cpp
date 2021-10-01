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

int N;
int arr1[1001];
int arr2[1001];
int uphilldp[1001];
int downhilldp[1001];

// 사용 여부
bool check1[1001], check2[1001];

void input(){
    cin >> N;
    int a;
    for(int i = 0; i < N; i++){
        cin >> arr1[i];
        arr2[N-1-i] = arr1[i];
        uphilldp[i] = downhilldp[i] = 1;
    }
}

void findHighlight(){
    int ans = 1;
    int res1 = 1, res2 = 1, mid;
    
    
    // 0번 인덱스부터 감소하는 부분 수열
    for(int i = 0; i < N; i++){
        int start = arr1[i];
        for(int j = 0; j < i; j++){
            int now = arr1[j];
            if(start < now){
                uphilldp[i] = max(uphilldp[i], uphilldp[j]+1);
                if(uphilldp[i] < uphilldp[j] + 1){
                    check1[i] = true;
                }
            }
        }
        if(res1 > uphilldp[i]){
            res1 = uphilldp[i];
            mid = i;
        }
    }
    ans = max(ans, res1);
    
    // N-1번 인덱스부터 감소하는 부분 수열
    for(int i = 0; i < N; i++){
        int start = arr2[i];
        for(int j = 0; j < i; j++){
            int now = arr2[j];
            if(start < now){
                downhilldp[i] = max(downhilldp[i], downhilldp[j]+1);
                if(downhilldp[i] < downhilldp[j] + 1){
                    check2[i] = true;
                }
            }
        }
        res2 = max(res2, downhilldp[i]);
    }
    ans = max(ans, res2);
    
    // 가운데 기둥을 사용했는지??
    // 둘다 사용했으면 1을 빼야하고, 아니면 그냥 더해주면 되는데
    
    // 교차점을 기준으로 계산
    for(int i = 0; i < N; i++){
        int lo = uphilldp[i];
        int hi = downhilldp[N-1-i];
        if(check1[i] && check2[N-1-i]){
            ans = max(ans, lo+hi-1);
        }
        else{
            ans = max(ans, lo+hi);
        }
    }
    
    
    cout << ans-1;
}


void solve(){
    // 하이라이트 구간을 찾아야 함 감소->증가, 단조 감소, 단조 증가
    // 중간의 기둥들을 삭제할 수 있음
    // 연속적으로 높이가 같은 기둥은 없어야 함
    // 하이라이트 구간을 어떻게 찾을지?
    
    // 임의의 구간을 매번 정해서 (N^2) 투포인터?
    // 1번과 n번을 잡아서 1번은 증가하는 방향으로, n번은 감소하는 방향으로 기둥을 본다
    // 1번 기둥은 다음 기둥이 반드시 감소해야함
    // n번 기둥은 다음 기둥이 증가해도 되고, 감소해도됨
    // 하지만 1번과 n번의 바로 다음 증가, 감소 결과에 따라서 그 결과를 계속 이어나간다.
    // 만약 감소하다가 갑자기 증가하게되면 해당 기둥을 삭제. 
    // 중간에서 만나면 시작 구간에 대한 답을 dp 배열에 저장한다.
    // 구간에 대한 답을 dp로 저장
    
    // #2
    // 증가하는 최장 부분 수열 + 감소하는 최장 부분 수열
    
    findHighlight();
}

int main(){
    input();
    solve();
    
    return 0;
}
