// 실행시간 40 ms
//우선순위 큐를 사용하면 실행시간을 절반 단축시킬 수 있을 듯 함


#include <iostream>
#include <set>
#include <vector>

using namespace std;
vector<int> result;
multiset<int> arr;
int N, x;

void solve(){
    for(int i = 0; i < N; i++){
        cin >> x;
        if(x == 0){
            if(arr.size() == 0){
                result.push_back(0);
            }
            else{
                result.push_back(*(arr.begin()));
                arr.erase(arr.begin());
            }
        }
        else if(x > 0){
            arr.insert(x);
        }
    }
    for(auto w : result){
        cout << w << "\n";
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    solve();
    return 0;
}
