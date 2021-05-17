#include <iostream>
#include <vector>
using namespace std;

class Fence{
    vector<int> h;

public:
    Fence(){
        int n;
        cin >> n;
        h.resize(n);
        for(int i = 0; i < n; i++){
            cin >> h[i];
        }
    }

    //O(n^2) 완전탐색
    /*
    int bruteForce(){
        int ret = 0;
        int N = h.size();
        for(int left = 0; left < N; left++){
            int minheight = h[left];
            for(int right = left; right < N; right++){
                minheight = min(minheight, h[right]);
                ret = max(ret, (right - left + 1) * minheight);
            }
        }
        return ret;
    }*/

    int h_len(){
        return h.size();
    }

    //처음엔 left = 0, right = h의 크기
    int divide_fence(int left, int right){
        if(left == right) return h[left];

        int mid = (left + right) / 2;
        int lo = mid, hi = mid + 1;

        int res = max(divide_fence(left, lo), divide_fence(hi, right));

        int height = min(h[lo], h[hi]);

        res = max(res, height * 2);

        while(left < lo || hi < right){
            // lo가 left보다 커서 lo--를 할 수 있어야 하고,
            // hi가 right와 같아서 lo를 --할 수 밖에 없거나, h[--lo] 가 h[++hi] 보다 크면
            // lo를 --시켜서 높이를 조정한다
            if(lo > left && (hi == right || h[lo - 1] > h[hi + 1])){
                lo--;
                height = min(height, h[lo]);
            }
            else{
                hi++;
                height = min(height, h[hi]);
            }
            res = max(res, height * (hi - lo + 1));
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        Fence f1;
        cout << f1.divide_fence(0, f1.h_len()-1) << "\n";
    }
    return 0;
}
