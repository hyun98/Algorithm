#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

struct F{
    string name;
    int grade;
};

int N, K;
deque<F> gf;

void solve(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string tname;
    int tgrade;
    long long cnt = 0;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        F temp;
        cin >> tname;
        temp.name = tname;
        temp.grade = i+1;
        gf.push_back(temp);
    }

    sort(gf.begin(), gf.end(), [](F a, F b){return a.name.length() < b.name.length();});

    while(gf.size() != 1){
        int j = 1;
        while(gf[0].name.length() == gf[j].name.length()){
            if( gf[j].grade - gf[0].grade <= K ){
                cnt++;
                j++;
                continue;
            }
            break;
        }
        gf.pop_front();
    }
    cout << cnt;
}

int main(){
    solve();
    return 0;
}
