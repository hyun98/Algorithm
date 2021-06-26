#include <iostream>
#include <vector>

using namespace std;

struct Point{
    long long x, y;
    bool operator<=(Point &p1){
        if(x == p1.x){
            return y <= p1.y;
        }
        return x <= p1.x;
    }
};

int N;
vector<Point> poly;
Point friends[3];

void input(){
    cin >> N;
    long long a, b;
    
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        poly.push_back({a, b});
    }
    for(int i = 0; i < 3; i++){
        cin >> a >> b;
        friends[i] = {a, b};
    }
}
int CCW(const Point& p1, const Point& p2, const Point& p3){
    double res = (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y) - \
                    (p2.x*p1.y + p3.x*p2.y + p1.x*p3.y);
    
    if(res > 0) return 1;   // 반시계
    else if(res < 0) return -1;     // 시계
    else return 0;
}

bool isline_intersect(Point &a, Point &b, Point &c, Point &d){
    int std1, std2;
    
    std1 = CCW(a, b, c) * CCW(a, b, d);
    std2 = CCW(c, d, a) * CCW(c, d, b);
    
    if(std1 <= 0 && std2 <= 0){
        if(std1 == 0 && std2 == 0){     //선분이 일직선인 경우
            if(b <= a) swap(a, b);
            if(d <= c) swap(c, d);
            
            return a <= d && c <= b;
        }
        else return true;   //일직선이 아니면 교차함
    }
    else return false;  //CCW가 같은 방향이 있으면 
}

int isSafe(Point &A){
    Point inf;
    inf.x = 1000000001;
    inf.y = A.y;
    
    int cnt = 0;
    
    for(int i = 0; i < N; i++){
        Point p1 = poly[i];
        Point p2 = poly[(i+1)%poly.size()];
        
        // 꼭짓점에 있는 경우
        if(p1.x == A.x && p1.y == A.y){
            return 1;
        }
        // A가 p1p2선분 위에 있는 경우
        else if(isline_intersect(A, A, p1, p2)){
            return 1;
        }
        
        if(isline_intersect(A, inf, p1, p2)) cnt++;
    }
    return cnt % 2;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    input();

    for(int i = 0; i < 3; i++){
        cout << isSafe(friends[i]) << "\n";
    }
}