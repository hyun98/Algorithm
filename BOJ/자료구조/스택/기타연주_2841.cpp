#include <iostream>
#include <stack>
using namespace std;

void solve(){
    int N, P;
    stack<int> guitar[7];
    int string_num, fret, cnt = 0;
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> P;
    for(int i = 0; i < N; i++){
        cin >> string_num >> fret;

        while(!guitar[string_num].empty() && guitar[string_num].top() > fret){
            guitar[string_num].pop();
            cnt++;
        }

        if(guitar[string_num].empty() || guitar[string_num].top() < fret){
            guitar[string_num].push(fret);
            cnt++;
        }
    }
    cout << cnt;
}

int main(){
    solve();
    return 0;
}
