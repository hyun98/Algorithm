#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, arr[1001]={0, }, dp[1001], mem[1001];
vector<int> ans;

inline void input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < 1000; i++){
        dp[i] = 1;
        mem[i] = i;
    }
}

int union_find(int result_index){
    ans.push_back(arr[result_index]);
    
    if(result_index == mem[result_index]){
        return mem[result_index];
    }
    else{
        return union_find(mem[result_index]);
    }
}

void solve(){
    
    int result = 1, result_index = 1;
    
    for(int i = 1; i <= N; i++){
        int start = arr[i];
        for(int j = 1; j < i; j++){
            int now = arr[j];
            if(start > now){
                if(dp[j]+1 >= dp[i]){
                    dp[i] = dp[j] + 1;
                    mem[i] = j;
                }
//                else{
//                    mem[i] = i;
//                }
            }
        }
        if(dp[i] > result){
            result = dp[i];
            result_index = i;
        }
    }
    
//    for(int i = 1; i <= N; i++){
//        cout << mem[i] << " ";
//    }
//    cout << endl;
    
    union_find(result_index);
    cout << result << endl;
    reverse(ans.begin(), ans.end());
    for(auto w : ans){
        cout << w << " ";
    }
    
}

int main(){
    input();
    solve();
    
    return 0;
}
