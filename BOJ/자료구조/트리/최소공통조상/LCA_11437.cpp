#include <iostream>
#include <vector>
using namespace std;

// 걸린시간 기준 백준 꼴지 풀이ㅋㅋ

struct node{
    node* top = NULL;
    int num = -1;
    int depth;
    vector<node*> child;
};

struct P{
    int x, y;
};

vector<P> lca_pair;
vector< vector<int> > input_node;
vector<node*> all_node;

bool *visit;
node* root ;

void Search_LCA(node* a, node* b){
    if(a->num == b->num){
        cout << a->num << "\n";
        return;
    }

    if(a->depth < b->depth) Search_LCA(a, b->top);
    else if(a->depth > b->depth) Search_LCA(a->top, b);
    else Search_LCA(a->top, b->top);
}

void solve(){
    for(int i = 0; i < lca_pair.size(); i++){
        Search_LCA(all_node[lca_pair[i].x], all_node[lca_pair[i].y]);
    }
}

void make_tree(node* &root, int now, int d){
    if(visit[now]) return;

    int len = input_node[now].size();
    root->depth = d;
    root->num = now;
    visit[now] = true;
    all_node[now] = root;
    root->child.resize(len);
    d++;
    for(int i = 0; i < len; i++){
        int next = input_node[now][i];
        if(visit[next]) continue;

        root->child[i] = new node;
        root->child[i]->top = root;
        make_tree(root->child[i], next, d);
    }
}

void input(){
    int N, M, top, child, a, b;
    cin >> N;
    visit = new bool[N+1] {false};
    input_node.resize(N+1, vector<int>());
    all_node.resize(N+1);
    for(int i = 0; i < N-1; i++){
        cin >> top >> child;
        input_node[top].push_back(child);
        input_node[child].push_back(top);
    }
    cin >> M;
    P temp;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        temp.x = a;
        temp.y = b;
        lca_pair.push_back(temp);
    }
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    root = new node;
    make_tree(root, 1, 0);
    solve();

    return 0;
}
