#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

#define For(N) for(int i = 1; i <= N; i++)
using namespace std;

deque<int> circle;
int temp, M, N, counting = 0;
vector<int> pop_num;

void to_left(){
    temp = circle.front();
    circle.pop_front();
    circle.push_back(temp);
}

void to_right(){
    temp = circle.back();
    circle.pop_back();
    circle.push_front(temp);
}

void solve(){
    for(auto i : pop_num){
        int mid = circle.size() / 2;
        int lookingfor_nums_index;
        lookingfor_nums_index = int(find(circle.begin(), circle.end(), i) - circle.begin());

        if(lookingfor_nums_index <= mid){
            while(i != circle.front()){
                to_left();
                counting++;
            }
            circle.pop_front();
        }
        else{
            while(i != circle.front()){
                to_right();
                counting++;
            }
            circle.pop_front();
        }
    }
    cout << counting << endl;
}

int main(){
    // N <= 50
    // M <= N
    cin >> N >> M;
    For(N){
        circle.push_back(i);
    }
    int a;
    For(M){
        cin >> a;
        pop_num.push_back(a);
    }
    solve();

    return 0;
}
