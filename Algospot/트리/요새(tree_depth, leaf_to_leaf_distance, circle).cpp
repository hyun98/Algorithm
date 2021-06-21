#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//Ʈ���� ����, ���� �ָ� ������ leaf������ �Ÿ�, leaf ���� Ʈ�������, �� ����

struct fort{
    fort* parent;   //��� ������ �׳�
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

    //��κ� longest�� ũ���� h�� ���� ���ϴ� ������ ����Ʈ���� ��� �����ε�
    return max(longest, h);
}

int sdist(fort* a, fort* b){
    return pow(a->x - b->x, 2) + pow(a->y - b->y, 2);
}

//a�� b�� ���ΰ� �ִ��� �˾ƺ��� �Լ�
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

    // �̸� ������ ũ�������� ������ ��(��������)
    sort(tempfort.begin(), tempfort.end(), [](fort* a, fort* b){return a->r < b->r;});

    // �ڽ��� �����ϴ� ������ ���� ���� ������ �ڽ��� �θ𼺺��� �ȴ�
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
