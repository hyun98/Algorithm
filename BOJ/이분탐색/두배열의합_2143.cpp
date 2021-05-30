#include <bits/stdc++.h>

using namespace std;

int T, N, M;
long long A[1001], B[1001], PA[1001], PB[1001];
vector<long long> subA, subB;

void solve(){
    long long tw, cnt = 0;
    for(auto w : subA){
//        if(w >= T) break;
        tw = T - w;
        
        auto itrl = lower_bound(subB.begin(), subB.end(), tw);
        auto itru = upper_bound(subB.begin(), subB.end(), tw);
        cnt += (itru - itrl);
//        itr--;
//        for(; itr >= subB.begin(); itr--){
//            if(*itr != tw) break;
//            cnt++;
//        }
    }
    
    cout << cnt;
}

void init(){
    cin >>T;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    cin >> M;
    for(int i = 1; i <= M; i++){
        cin >> B[i];
    }
    
    // 누적합 배열 구하기
    PA[0] = 0;
    PB[0] = 0;
    for(int i = 1; i <= N; i++){
        PA[i] = PA[i-1] + A[i];
    }
    for(int i = 1; i <= M; i++){
        PB[i] = PB[i-1] + B[i];
    }
    
    // 모든 부 배열의 합 구하기
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j++){
            subA.push_back(PA[j] - PA[j-i]);
        }
    }
    for(int i = 1; i <= M; i++){
        for(int j = i; j <= M; j++){
            subB.push_back(PB[j] - PB[j-i]);
        }
    }
    
//    sort(subA.begin(), subA.end());
    sort(subB.begin(), subB.end());
}

int main(){
    init();
    solve();
    
    return 0;
}
