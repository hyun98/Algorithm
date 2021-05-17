#include <iostream>
#include <set>
using namespace std;

struct A{
    int val;
    int ab;
};

struct myorder{
    bool operator() (const A& a, const A& b) const{
        if(a.ab == b.ab){
            return a.val < b.val;
        }
        return a.ab < b.ab;
    }
};

multiset<A, myorder> heap;

void solution(){
    A result = *heap.begin();
    heap.erase(heap.begin());
    cout << result.val << "\n";
}

void input(){
    int N;
    A temp;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> temp.val;
        temp.ab = abs(temp.val);
        if(temp.val == 0){
            if(heap.size() == 0){
                cout << 0 << "\n";
                continue;
            }
            solution();
        }
        else{
            heap.insert(temp);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    return 0;
}
