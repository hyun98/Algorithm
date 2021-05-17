#include <iostream>
#include <algorithm>
#define INF 2e9+7
using namespace std;

int N, arr[100001], res[2];

void solution(){
    int lo = 0;
    int hi = N-1;
    
    int pivot_val = INF;
    int temp_val = abs(arr[lo] + arr[hi]);
    
    while(lo != hi){
        if(temp_val < pivot_val){
            res[0] = arr[lo];
            res[1] = arr[hi];
            pivot_val = temp_val;
        }
        
        int lo_hishl = arr[lo] + arr[hi-1];
        int loshr_hi = arr[lo+1] + arr[hi];
        
        if(abs(lo_hishl) < abs(loshr_hi)){
            hi--;
            temp_val = abs(lo_hishl);
        }
        else{
            lo++;
            temp_val = abs(loshr_hi);
        }
        
    }
    
    cout << res[0] << " " << res[1];
}

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
}

void sys_solve2470(){
    input();
    solution();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    sys_solve2470();
    
    return 0;
}
