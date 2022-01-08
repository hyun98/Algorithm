#include <iostream>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int N, M;
int arr[100001];
int parr[100001];

int main(){
    fastio
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        parr[i] = parr[i-1] + arr[i];
    }
    
    int l, r;
    for(int i = 0; i < M; i++){
        cin >> l >> r;
        cout << parr[r] - parr[l-1] << "\n";
    }
    
    return 0;
}
