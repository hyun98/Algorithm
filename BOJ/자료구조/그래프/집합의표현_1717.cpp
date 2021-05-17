#include <cstdio>
#include <vector>
using namespace std;

vector<int> value;

int find(int n){
    if(value[n] == n){  //최상위 노드인지 알아보는 과정
        return n;
    }
    else{
        return value[n] = find(value[n]);
    }
}

void union_set(int a, int b){
    int top_a = find(a);
    int top_b = find(b);

    value[top_b] = top_a;
}

int main(){
    int n, m, operate, a, b;
    scanf("%d %d", &n, &m);

    for(int i = 0; i <= n; i++){
        value.push_back(i);
    }

    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &operate, &a, &b);
        if(operate == 0){
            union_set(a, b);
        }
        else{
            if(find(a) == find(b)){
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
        }
    }
    return 0;
}
