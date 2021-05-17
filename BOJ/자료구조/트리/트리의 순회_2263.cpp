#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> inorder, postorder;
int x, root_index[100001];

//vector를 인자로 넣으면 재귀함수가 반복되면서 계속 호출됨 -> 메모리터짐
void preorder(int inl, int inr, int postl, int postr){
    if(inl > inr) return;

    int root = postorder[postr];
    int ridx = root_index[root];

    cout << root << " ";
    preorder(inl, ridx-1, postl, postl+(ridx-inl)-1);
    preorder(ridx+1, inr, postl+(ridx-inl), postr-1);

}

void input(int &N){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        inorder.push_back(x);
    }
    for(int i = 0; i < N; i++){
        cin >> x;
        postorder.push_back(x);
    }
    for(int i = 0; i < N; i++){
        root_index[inorder[i]] = i;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    input(N);
    preorder(0, N-1, 0, N-1);
    return 0;
}
