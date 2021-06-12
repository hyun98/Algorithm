#include <iostream>

using namespace std;

struct P{
    long long x, y;
};

struct Line{
    P p1, p2;  
};

Line line[2];

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

void line_sort(Line &l1){
    if(l1.p1.x > l1.p2.x){
        swap(l1.p1, l1.p2);
    }
}

bool isline_intersect(Line& l1, Line &l2){
    int std1, std2;
    
    std1 = CCW(l1.p1, l1.p2, l2.p1) * CCW(l1.p1, l1.p2, l2.p2);
    std2 = CCW(l2.p1, l2.p2, l1.p1) * CCW(l2.p1, l2.p2, l1.p2);
    
    if(std1 <= 0 && std2 <= 0){
        if(std1 == 0 && std2 == 0){     //선분이 일직선인 경우
            if(l1.p1.x <= l2.p1.x){
                // l1.p1.x------l2.p1.x----l1.p2.x----l2.p2.x
                if(l1.p2.x >= l2.p1.x) return true;
                else return false;
            }
            else{
                // l2.p1.x------l1.p1.x----l2.p2.x----l1.p2.x
                if(l2.p2.x >= l1.p1.x) return true;
                else return false;
            }
        }
        else return true;   //일직선이 아니면 교차함
    }
    else return false;  //CCW가 같은 방향이 있으면 
}

void solve(){
    if(isline_intersect(line[0], line[1])){
        cout << 1;
    }
    else cout << 0;
}

void input(){
    long long x1, x2, y1, y2;
    P p1, p2;
    for(int i = 0 ; i < 2; i++){
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        line[i].p1 = p1;
        line[i].p2 = p2;
        
        line_sort(line[i]);
    }
}

int main(){
    
    input();
    solve();
    
    return 0;
}