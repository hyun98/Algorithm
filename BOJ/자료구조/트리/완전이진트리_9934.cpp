#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int k, End = 2, tree[11][512];
vector<int> num(1024), depth_idx(10);

void building(int start,int end, int depth) {
    if (end - start < 0) {
        return;
    }
    int mid = (start + end) / 2;
    tree[depth][depth_idx[depth]++] = num[mid];
    building(start, mid-1, depth+1);
    building(mid+1, end, depth+1);
}

int main() {
    cin >> k;
    End = pow(2, k);
    for (int i = 1; i < End; i++){
        cin >> num[i];
    }

    building(1,End-1,0);

    for (int i = 0; i < k; i++) {
        End = pow(2, i);
        for (int j = 0; j < End; j++) {
            cout << tree[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
