#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N;
vector<int> students;

void input(){
    cin >> N;
    int co;
    for(int i = 0; i < N; i++){
        cin >> co;
        students.push_back(co);
    }
    
    sort(students.begin(), students.end());
}

void solve(){

    ll answer = 0;
    
    for(int i = 0; i < N - 2; i++){
        for(int j = i + 2; j < N; j++){
            int loCoding = students[i];
            int hiCoding = students[j];
            int need = 0 - (loCoding + hiCoding);
            
            int lower = lower_bound(students.begin() + i + 1, students.begin() + j, need) - students.begin();
            int upper = upper_bound(students.begin() + i + 1, students.begin() + j, need) - students.begin();
            
            if(lower == upper) continue;
            
            answer += (upper - lower);
        }
    }    
    cout << answer;
}

int main(){
    input();
    solve();
    
    return 0;
}
