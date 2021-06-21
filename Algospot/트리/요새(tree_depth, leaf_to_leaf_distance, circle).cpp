#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//트리의 깊이, 가장 멀리 떨어진 leaf사이의 거리, leaf 부터 트리만들기, 원 구현

struct fort{
    fort* parent;   //없어도 되지만 그냥
    int x, y, r;
    vector<fort*> children;
};

fort* root;
int x[101], y[101], r[101];
vector<fort*> tempfort;
int longest = 0;

int height(fort* root){

    int h = 0;

    vector<int> depth;

    for(int i = 0; i < root->children.size(); i++){
        h = max(h, height(root->children[i])+1);
        depth.push_back(h);
    }
    if(depth.empty()) return 0;
    sort(depth.begin(), depth.end());

    if(depth.size() >= 2){
        longest = max(longest, depth[depth.size()-2] + depth[depth.size()-1]);
    }

    return depth.back();
}

int solve(fort* root){
    int h = height(root);

    //대부분 longest가 크지만 h와 굳이 비교하는 이유는 선형트리일 경우 때문인듯
    return max(longest, h);
}

int sdist(fort* a, fort* b){
    return pow(a->x - b->x, 2) + pow(a->y - b->y, 2);
}

//a가 b를 감싸고 있는지 알아보는 함수
bool isenclose(fort* a, fort* b){
    return a->r > b->r && sdist(a, b) < pow(a->r - b->r, 2);
}

void fortress(){
    int N, x, y, r;
    root = new fort;
    cin >> N;
    fort* temp = new fort;

    for(int i = 0; i < N; i++){
        cin >> x >> y >> r;
        temp = new fort;
        temp->x = x;
        temp->y = y;
        temp->r = r;
        tempfort.push_back(temp);
    }

    // 미리 성벽을 크기순서대로 정렬해 둠(오름차순)
    sort(tempfort.begin(), tempfort.end(), [](fort* a, fort* b){return a->r < b->r;});

    // 자신을 포함하는 성벽중 가장 작은 성벽이 자신의 부모성벽이 된다
    for(int i = 0; i < tempfort.size() - 1; i++){
        for(int j = i+1; j < tempfort.size(); j++){
            if(isenclose(tempfort[j], tempfort[i])){
                if(j == tempfort.size()-1){
                    root->children.push_back(tempfort[i]);
                    tempfort[i]->parent = root;
                }
                else{
                    tempfort[i]->parent = tempfort[j];
                    tempfort[j]->children.push_back(tempfort[i]);
                }
                break;
            }

        }
    }

    cout << solve(root) << endl;
}

int main(){
    int C;
    cin >> C;

    for(int i = 0; i < C; i++){
        fortress();
    }

    return 0;
}
