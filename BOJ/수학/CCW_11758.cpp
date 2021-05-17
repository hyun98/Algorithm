#include <iostream>

using namespace std;

struct Point{
    int x, y;
};

Point P[3];

inline void input(){
    int a, b;
    for(int i = 0; i < 3; i++){
        cin >> a >> b;
        P[i] = {a, b};
    }
}

int CCW(const Point p1, const Point p2, const Point p3) {
    // 사선 공식에서 추론
    int res = (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y) - (p2.x*p1.y + p3.x*p2.y + p1.x*p3.y);
    
    if(res > 0) return 1;   // 반시계
    else if(res < 0) return -1;    // 시계 방향
    else return 0;
}

int main(){
    input();
    cout << CCW(P[0], P[1], P[2]);
    return 0;
}
