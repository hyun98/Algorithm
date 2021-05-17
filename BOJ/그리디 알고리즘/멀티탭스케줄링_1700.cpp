#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, result = 0;
vector<int> UseList, MultiTap;

bool inTap(int now){
    for(int i = 0; i < MultiTap.size(); i++){
        if(MultiTap[i] == now) return true;
    }
    return false;
}

void plug_out(int useord){
    int fall_idx = 0, mul_idx = 0;
    for(int i = 0; i < MultiTap.size(); i++){
        bool check = false;
        for(int j = useord; j < UseList.size(); j++){
            if(UseList[j] == MultiTap[i]){
                if(fall_idx < j){
                    fall_idx = j;
                    mul_idx = i;
                }
                check = true;
                break;
            }
        }
        if(!check){
            mul_idx = i;
            break;
        }
    }
//    cout << "현재 선택 : " << UseList[useord] << "\n";
//    cout << MultiTap[mul_idx] << " 를 뽑습니다\n";
    MultiTap[mul_idx] = UseList[useord];
    result++;
}

void solve(){
    for(int i = 0; i < UseList.size(); i++){
        int now_use = UseList[i];
        if(inTap(now_use)) continue;
        
        if(MultiTap.size() < N) MultiTap.push_back(now_use);
        else plug_out(i);
    }
    
    cout << result;
}

void input(){
    cin >> N >> K;
    int temp;
    for(int i = 0; i < K; i++){
        cin >> temp;
        UseList.push_back(temp);
    }
}

int main(){
    input();
    solve();
    return 0;
}
