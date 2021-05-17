#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct dia{
    int wei, val;
};

struct pqcmp {
    bool operator()(const dia& root, const dia& c) {
        if(root.val == c.val) return root.wei > c.wei;
        return root.val < c.val;   // root와 c를 비교해서 참이면 교환 -> 내림 차순 
    }
};

bool cmp(const dia& a, const dia& b){
    if(a.wei == b.wei) return a.val < b.val;
    else return a.wei < b.wei;
}

int N, K;

priority_queue<dia, vector<dia>, pqcmp> rob;
vector<dia> Jew;
vector<int> bag;

void solve(){
    long long result = 0;
    int jew_idx = 0;
    
    for(int i = 0; i < bag.size(); i++){
        
        while(jew_idx < Jew.size()){
            if(Jew[jew_idx].wei > bag[i]) break;
            rob.push(Jew[jew_idx]);
            jew_idx++;
        }
        
        if(!rob.empty()){
            result += rob.top().val;
            rob.pop();
        }
    }
    
    cout << result;
}

void input(){
    cin >> N >> K;
    
    dia temp;
    for(int i = 0; i < N; i++){
        cin >> temp.wei >> temp.val;
        Jew.push_back(temp);
    }
    sort(Jew.begin(), Jew.end(), cmp);
    
    int t;
    for(int i = 0; i < K; i++){
        cin >> t;
        bag.push_back(t);
    }
    sort(bag.begin(), bag.end());
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solve();
    
    return 0;
}
