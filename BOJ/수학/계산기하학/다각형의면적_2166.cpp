#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct P{
    double x, y;
};

vector<P> points;
P pivot;

// 헤론의 공식
// double triangle_Area(P p1, P p2, P p3){
//    double a = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
//    double b = sqrt(pow(p2.x - p3.x, 2) + pow(p2.y - p3.y, 2));
//    double c = sqrt(pow(p3.x - p1.x, 2) + pow(p3.y - p1.y, 2));
   
//    double s = (a + b + c)/2;
//    double area = sqrt(s *(s-a)*(s-b)*(s-c));
//    return area;
// }

// 사선공식
double triangle_Area(P p1, P p2, P p3){
//    double area = (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - p1.y*p2.x - p2.y*p3.x - p3.y*p1.x) / 2.0;
    double area = (double)((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y)) / 2.0;
    return area;
}

// int CCW(P p1, P p2, P p3) {
//     long long res = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - p1.y*p2.x - p2.y*p3.x - p3.y*p1.x;
//     if(res > 0) return 1;
//     else if(res < 0) return -1;
//     else return 0;
// }

void solve(){
    // -1:clock, 0:line, 1:counter clock
    // int direction;
    double result = 0;
    
    for(int i = 1; i < points.size()-1; i++){
        P P2, P3;
        P2 = points[i];
        P3 = points[i+1];
        
        // direction = CCW(P1, P2, P3);
        
        result += (triangle_Area(pivot, P2, P3));
    }
    
    result = abs(result);
    printf("%.1lf\n", result);
    // cout << round(result*10.0)/10.0;
}

void input(){
    int N;
    double a, b;
    cin >> N;
    // cin >> pivot.x >> pivot.y;
    for(int i = 1; i <= N; i++){
        cin >> a >> b;
        points.push_back({a, b});
    }
    pivot = points[0];
}

int main(){
    input();
    solve();
    
    return 0;
}
