#include <bits/stdc++.h>

using namespace std;

int N;
string res = "", num = "123";

bool is_bad(){
    int mid = res.size()/2;
     
    for(int start = 0; start < res.size(); start++){
        int lolen = (res.size() - start)/2;
        string lo = res.substr(start, lolen);
        string hi = res.substr(start + lolen, res.size() - (start+lolen));
        if(lo == hi) return true;
    }
    return false;
}

void dfs(int pos){
    // 매번 실행 할 때마다 지금까지 만들어진 수열이 좋은 수열인지 확인
    if(is_bad()) return;
    
    // 좋은 수열 테스트를 통과하고 + N개의 수로 이루어 졌으면 출력하고 exit 종료
    // 가장 먼저 나온 좋은 수열이 가장 작은 좋은 수열인게 자명하다
    if(pos == N){
        cout << res;
        exit(0);
    }
    
    for(int i = 0; i < 3; i++){
        res += num[i];
//        cout << "now : " << res << endl;
        dfs(pos+1);
        res.erase(pos);
    }
    
}

int main(){
    cin >> N;
    dfs(0);
    
    return 0;
}
