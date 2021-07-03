#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

struct Point{
    ll x, y;
    ll p, q;
    Point(ll x = 0, ll y = 0) : x(x), y(y), p(0), q(0) {}
};

int N, S;
Point convex[100001];

int CCW(const Point &p1, const Point &p2, const Point &p3){
    ll res = (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y) - \
                    (p2.x*p1.y + p3.x*p2.y + p1.x*p3.y);
    if(res > 0) return 1;   //반시계
    else if(res < 0) return -1;     //시계
    else return 0;
}

ll det(const Point &p1, const Point &p2){
    ll res = (p1.p * p2.q - p1.q * p2.p);
    return res;
}

bool angle_sort(Point &p1, Point &p2){
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
    if(p1.x == p2.x){
        return p1.y < p2.y;
    }
    else return p1.x < p2.x;
}

void solve(){
    
    sort(convex, convex+S, angle_sort);

    for(int i = 1; i < S; i++){
        convex[i].p = convex[i].x - convex[0].x;
        convex[i].q = convex[i].y - convex[0].y;
    }
    
    sort(convex+1, convex+S, angle_sort);
    
    int r;
    for(r = S-1; convex[r].x == convex[0].x; r--);
    r++;
    reverse(convex + r, convex + S);
    
    cout << S << "\n";
    for(int i = 0; i < S; i++){
        cout << convex[i].x << " " << convex[i].y << "\n";
    }
}

void input(){
    cin >> N;
    int a, b, k = 0;
    char c;
    for(int i = 0; i < N; i++){
        cin >> a >> b >> c;
        if(c == 'N') continue;
        convex[k++] = Point(a, b);
    }
    S = k;
}

int main(){
    input();
    solve();
    return 0;
}
