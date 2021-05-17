#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct P{
    int x, y;
};

inline long long dist(P &a, P &b){
    return pow((a.x-b.x), 2) + pow((a.y-b.y), 2);
}
// x 오름차순 정렬
bool cmp(P &a, P &b){
    if(a.x == b.x) return a.y <= b.y;
    else return a.x <= b.x;
}
// y 오름차순 정렬
bool cmp_center(P &a, P &b){
    if(a.y == b.y) return a.x <= b.x;
    else return a.y <= b.y;
}

int N;
vector<P> Points;

void input(){
    cin >> N;
    Points.reserve(N+1);
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        Points.push_back({a, b});
    }
    sort(Points.begin(), Points.end(), cmp);
}

// st와 ed사이에 점 사이의 최단거리를 반환하는 함수
long long divide(int st, int ed){
    // 점이 2개 있을 때는 두 점사이의 거리를 반환
    if(ed - st == 1) return dist(Points[st], Points[ed]);
    
    // 점이 3개 있을 때는 점 사이의 거리를 각각 구해서 가장 짧은 값을 반환
    if(ed - st == 2){
        long long temp = min(dist(Points[st], Points[st+1]), dist(Points[st], Points[ed]));
        return min(temp, dist(Points[st+1], Points[ed]));
    }
    
    // 가운데 인덱스
    int mid = (st + ed) / 2;
    // 평면을 2분할 하는 y축과 평행한 기준선
    int xline = (Points[mid].x + Points[mid+1].x) / 2;
    // 현재 평면을 두 그룹으로 나누어서 해당 그룹에서의 최단거리 중 더 짧은 값을 d에 입력한다
    long long d = min(divide(st, mid), divide(mid, ed));
    if(d == 0) return 0;
    
    // xline에서 x좌표의 거리가 d보다 작은 점들을 모아주는 벡터
    vector<P> center;
    for(int i = st; i <= ed; i++){
        int t = xline - Points[i].x;
        // xline과 점들의 x좌표를 비교해서 그 간격이 d보다 작다면 center벡터에 push
        if(t*t < d) center.push_back(Points[i]);
    }
    
    //center벡터를 y좌표 오름차순으로 정렬
    sort(center.begin(), center.end(), cmp_center);
    
    int centerSize = center.size();
    // 정렬된 center벡터를 2개씩 묶어서 비교
    for(int i = 0; i < centerSize-1; i++){
        for(int j = i+1; j < centerSize; j++){
            long long td = dist(center[i], center[j]);
            // 두 점간의 거리가 d보다 크면 break
            // 2번째 for문을 break하는 이유는 center를 y 좌표 오름차순으로 정렬했기 때문에
            // 다음번 점과 비교해도 두 점간의 거리가 d보다 클 것이 자명하다
            if(td >= d) break;
            // 두 점이 서로 다른 그룹이면 현재 최솟값 d와 지금 보고있는 두 점간의 거리중 min값을 d에 입력
            if(xline - center[i].x >= 0 && center[j].x - xline >= 0){
                d = min(d, td);
            }
        }
    }
    
    return d;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    
    cout << divide(0, N-1);
    
    return 0;
}
