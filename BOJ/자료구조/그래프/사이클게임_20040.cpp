#include <iostream>
#include <cstring>
using namespace std;


int Node[500001];
int N, M;

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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    memset(Node, -1, sizeof(Node));
    
    int a, b, result = 1;
    bool cycle = false;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        if(is_cycle(a, b)) cycle = true;
        else{
            Union_node(a, b);
            if(!cycle) result++;
        }
    }
    cout << (cycle? result : 0);
    
    return 0;
}
