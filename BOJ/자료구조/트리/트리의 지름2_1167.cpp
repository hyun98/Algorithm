#include <bits/stdc++.h>
using namespace std;

struct node{
    int num;
    vector<int> weight;
    vector<int> connect;
};

vector<node> tree;
vector<int> result, visited;

int diameter(node now, int w){
    if(now.connect.empty()) return w;
    if(visited[now.num]) return 0;

    visited[now.num] = 1;
    vector<int> distance;

    for(int i = 0; i < now.connect.size(); i++){
        distance.push_back(diameter(tree[now.connect[i]], now.weight[i]));

    }

    sort(distance.begin(), distance.end());

    if(distance.size() >= 2){
        result.push_back(distance[distance.size()-1] + distance[distance.size()-2]);
    }
    else{
        result.push_back(distance.back());
    }

    return distance[distance.size()-1] + w;
}

void solve(){
    sort(result.begin(), result.end());
    cout << result.back();
}

void input(){
    int N, apex, to, wei;
    cin >> N;
    tree.resize(N+1);
    visited.resize(N+1, 0);
    for(int i = 0; i < N; i++){
        cin >> apex;
        tree[apex].num = apex;
        cin >> to;
        while(to != -1){
            cin >> wei;
            tree[apex].connect.push_back(to);
            tree[apex].weight.push_back(wei);
            cin >> to;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    diameter(tree[1], 0);
    solve();
    return 0;
}
