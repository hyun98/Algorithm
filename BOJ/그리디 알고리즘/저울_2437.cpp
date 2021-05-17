///         질문 게시판을 보고 나서야 이해한 문제
///         2021-03-05
///         어렵다고

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> weight;

void input(){
    cin >> N;
    weight.resize(N);
    for(int i = 0; i < N; i++){
        cin >> weight[i];
    }
    sort(weight.begin(), weight.end());
}

void solve(){
    int result = 1;
    int sum = 1;
    for(int i = 0; i < N; i++){
        if(weight[i] > sum) break;
        else sum += weight[i];
    }
    
    cout << sum;
}

int main(){
    input();
    solve();
    
    return 0;
}









/// 시간초과 코드 유배
//bool check(int hi, int tnum){
//    int num = tnum;
//    while(hi >= 0){
//        if(num - weight[hi] == 0) return true;
//        else if(num - weight[hi] > 0){
//            num -= weight[hi];
//            hi--;
//        }
//        else hi--;
//    }
//    return false;
//}
//
//void solve(){
//    int num = 1;
//    while(true){
//        int hi;
//        int lo = 0;
//        for(int i = lo; i < weight.size(); i++){
//            if(num == weight[i]){
//                num+=1;
//                lo = i;
//                continue;
//            }
//            else if(num < weight[i]){
//                hi = i-1;
//                if(!check(hi, num)){
//                    result = num;
//                    return;
//                }
//                else{
//                    num += 1;
//                    continue;
//                }
//            }
//        }
//    }
//}
