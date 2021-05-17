#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

struct Line{
    int st;
    int ed;
    double value;
};

struct point{
    float x, y;  
};

vector<point> Stars;
vector<Line> Edge;
int N;
double result = 0;
int Node[10001];

bool compare(Line &a, Line &b){
    return a.value < b.value;
}

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
    int va, vb, cnt = 0;
    for(int i = 0; i < Edge.size(); i++){
        if(cnt == N-1) break;
        va = Edge[i].st;
        vb = Edge[i].ed;
        if(!is_cycle(va, vb)){
            Union_node(va, vb);
            result += Edge[i].value;
            cnt++;
        }
    }
    printf("%.2lf\n", result);
}

double dist(point &a, point &b){
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

void init(){
    float a, b;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        Stars.push_back({a, b});
    }
    
    for(int i = 0; i < N-1; i++){
        for(int j = 1; j < N; j++){
            Line temp;
            temp.st = i;
            temp.ed = j;
            temp.value = dist(Stars[i], Stars[j]);
            Edge.push_back(temp);
        }
    }
    
    sort(Edge.begin(), Edge.end(), compare);
    memset(Node, -1, sizeof(Node));
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    init();
    solve();
    
    return 0;
}