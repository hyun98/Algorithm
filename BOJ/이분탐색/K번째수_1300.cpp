#include <iostream>

using namespace std;

long long N, K;

// 행렬에서 mid와 같거나 작은수의 개수를 리턴
long long lessNum_inMatrix(long long mid){
    long long cnt = 0;
    for(int i = 1; i <= N; i++){
        // i행은 i의 배수의 집합이므로 
        // mid를 i로 나눠주면 mid가 i행에서 몇 번째에 위치하는지 알 수 있다
        // i행의 최댓값보다 mid/i가 더 크다면 N(행의 크기)을 cnt에 더해준다
        cnt += min(N, (long long)mid/i);
        if(i > mid) break;
    }
    return cnt;
}

void Matrix_BS(){
    long long lo = 1;
    long long hi = N*N;
    
    int res = 0;
    
    // lo가 hi와 같아지면 break
    while(lo <= hi){
        long long mid = (lo + hi)/2;
        // mid와 같거나 작은 값의 개수가 K보다 작으면
        if(lessNum_inMatrix(mid) < K) lo = mid + 1;
        else{
            res = mid;
            hi = mid - 1;
        }
    }
    cout << res;
}

int main(){
    cin >> N >> K;
    Matrix_BS();
    
    return 0;
}