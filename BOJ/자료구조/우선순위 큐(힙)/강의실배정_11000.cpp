#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct T{
    int st, ed;
};

int N;
vector<T> sched;
priority_queue< int, vector<int>, greater<int> > pq;

bool cmp(const T& a, const T& b){
    if(a.st == b.st) return a.ed < b.ed;
    else return a.st < b.st;
}

void solve(){
    pq.push(sched[0].ed);
    for(int i = 1; i < N; i++){
        if(sched[i].st >= pq.top()) pq.pop();
        pq.push(sched[i].ed);
    }
    
    cout << pq.size();
}

int main(){
    int s, e;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s >> e;
        sched.push_back({s, e});
    }
    sort(sched.begin(), sched.end(), cmp);
    
    solve();
    
    return 0;
}
