#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//¹Ì¿Ï¼º
struct P{
    bool visit = false;
    int num;
    priority_queue<int, vector<int>, greater<int> > prior;
};

int N, M, a, b, x;
P *problem;

int find_top(P &a){
    if(a.prior.empty()){
        a.visit = true;
        return a.num;
    }
    else{
        while(problem[a.prior.top()].visit){
            a.prior.pop();
            if(a.prior.empty()){
                a.visit = true;
                return a.num;
            }
        }
        return find_top(problem[a.prior.top()]);
    }
}

void solve(){
    cin >> N >> M;
    problem = new P[N+1];

    for(int i = 1; i <= N; i++){
        problem[i].num = i;
    }

    while(M--){
        cin >> a >> b;
        problem[b].prior.push(a);
    }

    int i = 1;
    while(i <= N){

        if(!problem[i].visit) cout << find_top(problem[i]) << " ";
        else i++;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();

    return 0;
}
