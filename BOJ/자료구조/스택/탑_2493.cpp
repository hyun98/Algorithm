#include <cstdio>
#include <vector>
using namespace std;

struct top{
    int H, I;
};

int N, height, id = 0;
vector<top> stack_A;

void solve(){
    stack_A.reserve(500001);
    scanf("%d", &N);

    for(int i = 1; i <= N; i++){
        scanf("%d", &height);
        while(id > 0){
            if(stack_A[id].H > height){
                printf("%d ", stack_A[id].I);
                break;
            }
            //새로 들어온 높이가 기존 스택의 마지막 높이보다 높으면 덮어쓴다
            else{
                id--;
            }
        }
        if(id == 0){
            printf("0 ");
        }
        id++;
        stack_A[id] = {height, i};
    }
}

int main(){
    solve();
    return 0;
}
