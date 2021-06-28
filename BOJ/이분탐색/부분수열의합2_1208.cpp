#include <iostream>
#include <map>
using namespace std;

int N, S;
int arr[41];
map<int, int> subsum;
long long cnt;

void rightSeq(int mid, int sum){
    if(mid == N){
        subsum[sum]++;
        return;
    }
    
    rightSeq(mid+1, sum+arr[mid]);
    rightSeq(mid+1, sum);
}

void leftSeq(int st, int sum){
    if(st == N/2){
        cnt += subsum[S-sum];
        return;
    }
    
    leftSeq(st+1, sum+arr[st]);
    leftSeq(st+1, sum);
}

int main(){
    cin >> N >> S;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    rightSeq(N/2, 0);
    leftSeq(0, 0);
    
    if(!S) cout << cnt-1;
    else cout << cnt;
    
    return 0;
}