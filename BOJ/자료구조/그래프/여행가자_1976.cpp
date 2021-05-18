#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int Node[201], visit_plan[1001];
int city_num, travel_num, link, plan_city;


int find_topnode(int a){
    if(Node[a] < 0) return a;
    return Node[a] = find_topnode(Node[a]);
}

bool is_cycle(int a, int b){
    a = find_topnode(a);
    b = find_topnode(b);
    if(a == b) return true;
    else return false;
}

void Union_node(int a, int b){
    a = find_topnode(a);
    b = find_topnode(b);
    if(Node[a] > Node[b]){
        Node[b] += Node[a];
        Node[a] = b;
    }
    else{
        Node[a] += Node[b];
        Node[b] = a;
    }
}

void solve(){
    int root;
    bool possible = true;
    
    for(int i = 1; i <= travel_num; i++){
        if(i == 1){
            root = find_topnode(visit_plan[1]);
            continue;
        }
        if(root != find_topnode(visit_plan[i])){
            possible = false;
            break;
        }
    }
    if(possible) cout << "YES";
    else cout << "NO";
}

void init(){
    cin >> city_num >> travel_num;
    
    memset(Node, -1, sizeof(Node));
    
    for(int i = 1; i <= city_num; i++){
        for(int j = 1; j <= city_num; j++){
            cin >> link;
            if(i == j) continue;
            if(link && !is_cycle(i, j)){
                Union_node(i, j);
            }
        }
    }
    
    for(int i = 1; i <= travel_num; i++){
        cin >> visit_plan[i];
    }
}

int main(){
    init();
    solve();
    
    return 0;
}
