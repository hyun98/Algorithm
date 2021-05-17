#include <iostream>

using namespace std;

class Select{
    int N;
    int order[100001];
    
public:
    Select(){
        int a, b;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> a >> b;
            order[a] = b;
        }
    }
    void solve(){
        int min_score, cnt = 1;
        min_score = order[1];
        for(int i = 2; i <= N; i++){
            if(order[i] < min_score){
                min_score = order[i];
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        Select S1;
        S1.solve();
    }
    return 0;
}
