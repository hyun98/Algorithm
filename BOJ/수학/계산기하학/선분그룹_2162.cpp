#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

struct P{
    long long x, y;
    bool operator<=(P const &p1) {
        if(x == p1.x){
            return y <= p1.y;
        }
        return x <= p1.x;
    }
};

struct Line{
    P p1, p2;  
};


Line line[3001];
int N, Node[3001];

int findTopnode(int a){
    if(Node[a] < 0) return a;
    return Node[a] = findTopnode(Node[a]);
}

bool is_cycle(int a, int b){
    a = findTopnode(a);
    b = findTopnode(b);
    if(a == b) return true;
    else return false;
}

void Union_node(int a, int b){
    a = findTopnode(a);
    b = findTopnode(b);
    
    if(Node[a] > Node[b]){
        Node[b] += Node[a];
        Node[a] = b;
    }
    else{
        Node[a] += Node[b];
        Node[b] = a;
    }
}

int CCW(const P &p1, const P &p2, const P &p3){
    long long res = (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y) - \
              (p2.x*p1.y + p3.x*p2.y + p1.x*p3.y);
    
    // 행렬식을 통해서 구하기
    // int determinant = (p2.x*p3.y - p2.y*p3.x) - \
    //                   (p1.x*p3.y - p1.y*p3.x) + \
    //                   (p1.x*p2.y - p1.y*p2.x);
    
    if(res > 0) return 1;   //반시계
    else if(res < 0) return -1;     //시계
    else return 0;
}

bool isline_intersect(Line& l1, Line &l2){
    int std1, std2;
    
    std1 = CCW(l1.p1, l1.p2, l2.p1) * CCW(l1.p1, l1.p2, l2.p2);
    std2 = CCW(l2.p1, l2.p2, l1.p1) * CCW(l2.p1, l2.p2, l1.p2);
    
    if(std1 <= 0 && std2 <= 0){
        if(std1 == 0 && std2 == 0){     //선분이 일직선인 경우
            if(l1.p2 <= l1.p1) swap(l1.p1, l1.p2);
            if(l2.p2 <= l2.p1) swap(l2.p1, l2.p2);
            
            return l1.p1 <= l2.p2 && l2.p1 <= l1.p2;
        }
        else return true;   //일직선이 아니면 교차함
    }
    else return false;  //CCW가 같은 방향이 있으면 
}

void solve(){
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            if(isline_intersect(line[i], line[j])){
                if(!is_cycle(i, j)){
                    Union_node(i, j);
                }
            }
        }
    }
    
    int groupNum = 0;
    int largest_groupnum = 0;
    
    for(int i = 0; i < N; i++){
        if(Node[i] < 0){
            groupNum++;
            largest_groupnum = max(largest_groupnum, abs(Node[i]));
        }
    }
    
    cout << groupNum << "\n" << largest_groupnum;
}

void input(){
    long long x1, x2, y1, y2;
    P p1, p2;
    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        line[i].p1 = p1;
        line[i].p2 = p2;
    }
    memset(Node, -1, sizeof(Node));
    
}

int main(){
    
    input();
    solve();
    
    return 0;
}
