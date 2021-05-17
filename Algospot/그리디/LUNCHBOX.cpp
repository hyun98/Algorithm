#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct T{
    int warm, eat;
};

bool cmp(const T &t1, const T &t2){
    return t1.eat > t2.eat;
}

class LUNCH{
    int n, w_sum = 0, e_sum = 0;
    vector<T> box;
public:
    LUNCH(){
        cin >> n;
        box.resize(n+1);
        for(int i = 0; i < n; i++){
            cin >> box[i].warm;
            if(i >= 1){
                w_sum += box[i].warm;
            }
        }
        for(int i = 0; i < n; i++){
            cin >> box[i].eat;
            e_sum += box[i].eat;
        }
        
        sort(box.begin(), box.end(), cmp);
    }
    
    void solve(){
        int ans = 0, start_eat = 0;
        for(int i = 0; i < n ; i++){
            start_eat += box[i].warm;
            ans = max(ans, start_eat + box[i].eat);
        }
        cout << ans << endl;
    }
    
};

int main(){
    int test;
    cin >> test;
    while(test--){
        LUNCH L1;
        L1.solve();
    }
    return 0;
}
