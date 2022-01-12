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
// x �������� ����
bool cmp(P &a, P &b){
    if(a.x == b.x) return a.y <= b.y;
    else return a.x <= b.x;
}
// y �������� ����
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

// st�� ed���̿� �� ������ �ִܰŸ��� ��ȯ�ϴ� �Լ�
long long divide(int st, int ed){
    // ���� 2�� ���� ���� �� �������� �Ÿ��� ��ȯ
    if(ed - st == 1) return dist(Points[st], Points[ed]);
    
    // ���� 3�� ���� ���� �� ������ �Ÿ��� ���� ���ؼ� ���� ª�� ���� ��ȯ
    if(ed - st == 2){
        long long temp = min(dist(Points[st], Points[st+1]), dist(Points[st], Points[ed]));
        return min(temp, dist(Points[st+1], Points[ed]));
    }
    
    // ��� �ε���
    int mid = (st + ed) / 2;
    // ����� 2���� �ϴ� y��� ������ ���ؼ�
    int xline = (Points[mid].x + Points[mid+1].x) / 2;
    // ���� ����� �� �׷����� ����� �ش� �׷쿡���� �ִܰŸ� �� �� ª�� ���� d�� �Է��Ѵ�
    long long d = min(divide(st, mid), divide(mid, ed));
    if(d == 0) return 0;
    
    // xline���� x��ǥ�� �Ÿ��� d���� ���� ������ ����ִ� ����
    vector<P> center;
    for(int i = st; i <= ed; i++){
        int t = xline - Points[i].x;
        // xline�� ������ x��ǥ�� ���ؼ� �� ������ d���� �۴ٸ� center���Ϳ� push
        if(t*t < d) center.push_back(Points[i]);
    }
    
    //center���͸� y��ǥ ������������ ����
    sort(center.begin(), center.end(), cmp_center);
    
    int centerSize = center.size();
    // ���ĵ� center���͸� 2���� ��� ��
    for(int i = 0; i < centerSize-1; i++){
        for(int j = i+1; j < centerSize; j++){
            long long td = dist(center[i], center[j]);
            // �� ������ �Ÿ��� d���� ũ�� break
            // 2��° for���� break�ϴ� ������ center�� y ��ǥ ������������ �����߱� ������
            // ������ ���� ���ص� �� ������ �Ÿ��� d���� Ŭ ���� �ڸ��ϴ�
            if(td >= d) break;
            // �� ���� ���� �ٸ� �׷��̸� ���� �ּڰ� d�� ���� �����ִ� �� ������ �Ÿ��� min���� d�� �Է�
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
