#include <iostream>
#include <array>

#define MAX 100001
using namespace std;

struct T{
    int tmax, tmin;
};

array<T, MAX * 4> tree;
array<int, MAX> my_data;
int N, M;

T init(int tree_begin, int tree_end, int node){
    if(tree_begin == tree_end){
        tree[node].tmax = my_data[tree_begin];
        tree[node].tmin = my_data[tree_begin];
       return tree[node];
    }
    int mid = (tree_begin + tree_end) / 2;
    T temp1 = init(tree_begin, mid, node*2);
    T temp2 =  init(mid+1, tree_end, node*2+1);

    if(temp1.tmin < temp2.tmin){
        tree[node].tmin = temp1.tmin;
    }
    else{
        tree[node].tmin = temp2.tmin;
    }
    if(temp1.tmax > temp2.tmax){
        tree[node].tmax = temp1.tmax;
    }
    else{
        tree[node].tmax = temp2.tmax;
    }

    return tree[node];
}

T sum(int part_left, int start_idx, int end_idx, int part_right, int node){
    if(part_left > end_idx || part_right < start_idx){
        T t = {0, 1000000001};
        return t;
    }

    if(part_left <= start_idx && end_idx <= part_right){
        return tree[node];
    }

    int mid = (start_idx + end_idx) / 2;
    T temp1 = sum(part_left, start_idx, mid, part_right, node*2);
    T temp2 = sum(part_left, mid+1, end_idx, part_right, node*2 + 1);

    T result;
    if(temp1.tmax > temp2.tmax){
        result.tmax = temp1.tmax;
    }
    else{
        result.tmax = temp2.tmax;
    }
    if(temp1.tmin < temp2.tmin){
        result.tmin = temp1.tmin;
    }
    else{
        result.tmin = temp2.tmin;
    }
    return result;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> my_data[i];
    }
    init(0, N-1, 1);
    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        cout << sum(a-1, 0, N-1, b-1, 1).tmin << " " << sum(a-1, 0, N-1, b-1, 1).tmax << "\n";
    }
    return 0;
}
