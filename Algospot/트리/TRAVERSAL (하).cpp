#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> slice(const vector<int> v, int a, int b){
    return vector<int>(v.begin() + a, v.begin() + b);
}

void postorder(vector<int> pretree, vector<int> intree){
    if(intree.empty()) return;

    int Num = intree.size();
    int root = pretree[0];

    int left = find(intree.begin(), intree.end(), root) - intree.begin();

    postorder(slice(pretree, 1, left+1), slice(intree, 0, left));
    postorder(slice(pretree, left+1, Num), slice(intree, left+1, Num));

    cout << root << " ";
}

void input(){
    int x, N;
    vector<int> pretree, intree;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        pretree.push_back(x);
    }
    for(int i = 0; i < N; i++){
        cin >> x;
        intree.push_back(x);
    }

    postorder(pretree, intree);
}

int main(){
    int C;
    cin >> C;
    for(int i = 0 ; i < C; i++){
        input();
    }
    return 0;
}
