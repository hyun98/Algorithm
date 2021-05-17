//Union-Find
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findtop(vector<int> node, int a){
    if(node[a] == a) return a;
    return findtop(node, node[a]);
}

void Union(vector<int> &node, int a, int b){
    a = findtop(node, a);
    b = findtop(node, b);
    if(a < b) node[b] = a;
    else if(a > b) node[a] = b;
    else return;
}

void solve(){
    int city_num, travel_num, link, plan_city;
    vector<int> visit_plan, Node;

    cin >> city_num >> travel_num;

    for(int i = 0; i < city_num; i++){
        Node.push_back(i);
    }

    for(int i = 0; i < city_num; i++){
        for(int j = 0; j < city_num; j++){
            cin >> link;
            if(link == 1) Union(Node, i, j);
        }
    }
    for(int i = 0; i < travel_num; i++){
        cin >> plan_city;
        visit_plan.push_back(plan_city-1);
    }

//    if(Node.size() == 0){
//        cout << "YES";
//        return;
//    }

    int root = findtop(Node, Node[0]);
    bool possible = true;
    for(int i = 1; i < travel_num; i++){
        if(root != findtop(Node, visit_plan[i])){
            possible = false;
            break;
        }
    }
    if(possible) cout << "YES";
    else cout << "NO";
}

int main(){
    solve();
    return 0;
}
