#include <iostream>
#include <queue>
using namespace std;

class Strjoin{
    int N;
    priority_queue<int, vector<int>, greater<int> > str_len;
public:
    Strjoin(){
        int l;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> l;
            str_len.push(l);
        }
    }
    
    void solve(){
        int a, b, result = 0;
        while(str_len.size() != 1){
            a = str_len.top(); str_len.pop();
            b = str_len.top(); str_len.pop();
            result += (a+b);
            str_len.push(a+b);
        }
        cout << result << "\n";
    }
};

int main(){
    int test;
    cin >> test;
    while(test--){
        Strjoin S1;
        S1.solve();
    }
    return 0;
}
