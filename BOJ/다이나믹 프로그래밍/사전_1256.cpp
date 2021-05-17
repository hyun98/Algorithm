#include <iostream>

using namespace std;


const int MOD = 1000000000;

string res = "";
// N개의 "a"와 M개의 "z"
int Combi[201][201];

void init_combi(){
    Combi[0][0] = 1;
    // i개 중 1개를 뽑는 경우의 수는 1가지
    for(int i = 1; i <= 200; i++){
        Combi[i][0] = 1;
        Combi[i][1] = i;
    }
    // i개 중 i개를 뽑는 경우의 수는 1가지
    for(int i = 1; i <= 200; i++){
        Combi[i][i] = 1;
    }
    
    // combination tree 만들기
    for(int i = 2; i <= 200; i++){
        for(int j = 2; j <= i-1; j++){
            int next = Combi[i-1][j-1] + Combi[i-1][j];
            if(next > MOD) Combi[i][j] = MOD;
            else Combi[i][j] = next;
        }
    }
}

void process(int N, int M, int K){
    int n = N+M-1, m = M, k = K;
    
    if(Combi[N+M][M] < K){
        cout << -1;
        return;
    }
    while(n >= 0){
        // 현재 자리가 'a'인 경우
//        cout << "combi[" << n << "][" << m << "] : " << Combi[n][m] << endl;
        if(Combi[n][m] >= k && n >= m){
            res += 'a';
            n--;
        }
        // 'z'인 경우
        else{
            res += 'z';
            k -= Combi[n][m];
            n--; m--;
        }
    }
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K;
    cin >> N >> M >> K;
    init_combi();
    process(N, M, K);
    
    return 0;
}
