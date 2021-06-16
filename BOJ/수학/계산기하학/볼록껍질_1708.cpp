#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

struct P{
    ll x, y;
    ll p, q;
    P(ll x = 0, ll y = 0) : x(x), y(y), p(0), q(0) {}
};

int N;
P points[100001];

int CCW(const P &p1, const P &p2, const P &p3){
    ll res = (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y) - \
                    (p2.x*p1.y + p3.x*p2.y + p1.x*p3.y);
    if(res > 0) return 1;   //반시계
    else if(res < 0) return -1;     //시계
    else return 0;
}

ll det(const P &p1, const P &p2){
    ll res = (p1.p * p2.q - p1.q * p2.p);
    return res;
}

bool angle_sort(P &p1, P &p2){
    if(p1.p != 0 || p1.q != 0 || p2.p != 0 || p2.q != 0){
        if(det(p1, p2) > 0){
            return true;
        }
        else if(det(p1, p2) == 0){
            return p1.p*p1.p + p1.q*p1.q < p2.p*p2.p + p2.q*p2.q;
        }
        else{
            return false;
        }
    }
    if(p1.y == p2.y){
        return p1.x < p2.x;
    }
    else return p1.y < p2.y;
}

void convex_hull(){
    vector<int> stk;
    
    sort(points, points+N, angle_sort);
    
    for(int i = 1; i < N; i++){
        points[i].p = points[i].x - points[0].x;
        points[i].q = points[i].y - points[0].y;
    }
    
    sort(points+1, points+N, angle_sort);
    
    int st, mid, ed = 2;
    stk.push_back(0); stk.push_back(1);
    
    while(ed != N){    // ed는 마지막 점까지 확인
        while(stk.size() >= 2){
            int mid = stk.back();
            stk.pop_back();
            int st = stk.back();
            
            if(CCW(points[st], points[mid], points[ed]) > 0){
                // 반시계 방향인 경우 mid는 convex hull에 임시 포함
                stk.push_back(mid);
                break;
            }
        }
        stk.push_back(ed++);
    }
    
    cout << stk.size();
}

void input(){
    int a, b;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        points[i] = P(a, b);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    input();
    convex_hull();
    
    return 0;
}