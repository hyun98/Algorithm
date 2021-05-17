#include <iostream>
#include <cstdio>

#define MAX 1000001
using namespace std;

long long tree[MAX * 4];
long long data[MAX];

long long init(int start_idx, int end_idx, int node){
    if(start_idx == end_idx){
        return tree[node] = data[start_idx];
    }

    int mid = (start_idx + end_idx) / 2;
    return tree[node] = init(start_idx, mid, node*2) + init(mid+1, end_idx, node*2+1);
}

void update(int start_idx, int end_idx, int node, int up_idx, long long modify){
    if(up_idx < start_idx || end_idx < up_idx){
        return;
    }
    tree[node] += modify;
    if(start_idx == end_idx){
        return;
    }
    int mid = (start_idx + end_idx) / 2;
    update(start_idx, mid, node*2, up_idx, modify);
    update(mid+1, end_idx, node*2+1, up_idx, modify);
}

long long sum(int part_left, int start_idx, int end_idx, int part_right, int node){
    if(start_idx > part_right || end_idx < part_left){
        return 0;
    }
    if(part_left <= start_idx && end_idx <= part_right){
        return tree[node];
    }

    int mid = (start_idx + end_idx) / 2;
    return sum(part_left, start_idx, mid, part_right, node*2)+
    sum(part_left, mid+1, end_idx, part_right, node*2+1);
}

int main(){
    //ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 수의 개수 N(1 ≤ N ≤ 1,000,000)
    // 수의 변경이 일어나는 횟수 M(1 ≤ M ≤ 10,000)
    // 구간의 합을 구하는 횟수 K(1 ≤ K ≤ 10,000)
    // a가 1인 경우 b번째 수를 c로 바꾸고
    // a가 2인 경우에는 b번째 수부터 c번째 수까지의 합을 구하여 출력
    int N, M, K, a;
    long long b, c;
    cin >> N >> M >> K;

    for(int i = 0; i < N; i++){
        scanf("%lld", &data[i]);
    }
    init(0, N-1, 1);
    for(int i = 0; i < M + K; i++){
        scanf("%d %d %lld", &a, &b, &c);
        if(a == 1){
            update(0, N-1, 1, b-1, c-data[b-1]);
            data[b-1] = c;
        }
        else if(a == 2){
            printf("%lld\n", sum(b-1, 0, N-1, c-1, 1));
        }
    }

    return 0;
}
