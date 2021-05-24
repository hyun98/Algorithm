#include <iostream>
#include <vector>

using namespace std;

#include <stdio.h>

// 소수면 1, 아니면 0
int N, Prime_number[4000001];
vector<int> Prime_list;     // 소수만 모아놓은 배열
int result = 0;

void che(){
    Prime_number[1] = 0;
    for(int i = 2; i <= N; i++){
        Prime_number[i] = 1; // 처음엔 모두 소수라고 가정
    }
    
    for(int i = 2; i <= N; i++){
        if(!Prime_number[i]) continue;
        
        for(int j = i * 2; j <= N; j += i){
            Prime_number[j] = 0;
        }
    }
    // 소수만 있는 prime_list를 만든다
    for(int i = 2; i <= N; i++){
        if(Prime_number[i]) Prime_list.push_back(i);
    }
}

void solve(){
    // 에라토스테네스의 체를 이용해 1~N까지의 소수를 구한다
    che();
    
    // N이 소수면 result는 1부터 시작
    if(Prime_number[N]) result++;
    
    // 소수 리스트에서의 인덱스
    int st = Prime_list.size()-2;
    int ed = Prime_list.size()-1;
    
    int sum = 0;
    for(int i = st; i <= ed; i++){
        sum += Prime_list[i];
    }
    
    while(st >= 0){
        if(sum > N){
            sum -= Prime_list[ed];
            ed--;
            
            if(st == ed){
                st--;
                sum += Prime_list[st];
            }
            
        }
        else if(sum == N){
            result++;
            sum -= Prime_list[ed];
            ed--;
        }
        else{
            st--;
            sum += Prime_list[st];
        }
    }
    
    cout << result;
}

int main(){
    cin >> N;
    if(N == 1){
        cout << 0;
        return 0;
    }
    solve();
    
    return 0;
}