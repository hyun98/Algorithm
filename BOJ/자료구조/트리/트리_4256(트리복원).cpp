#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> slice(const vector<int> &tree, int a, int b){
    return vector<int> (tree.begin()+a, tree.begin()+b);
}

void restore(vector<int> pre, vector<int> ino){
    if(ino.size() == 0){
        return;
    }
    int root = pre.front();

    int term = find(ino.begin(), ino.end(), root) - ino.begin();

    restore(slice(pre, 1, term+1), slice(ino, 0, term));
    restore(slice(pre, term+1, ino.size()), slice(ino, term+1, ino.size()));
    cout << root << " ";
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int n, x;
        vector<int> preorder, inorder;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x;
            preorder.push_back(x);
        }
        for(int i = 0; i < n; i++){
            cin >> x;
            inorder.push_back(x);
        }

        restore(preorder, inorder);
        cout << "\n";
    }
    return 0;
}
