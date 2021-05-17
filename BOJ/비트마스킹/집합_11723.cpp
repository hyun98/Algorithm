#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int S = 0, M, x;
    cin >> M;
    
    string oper;
    for(int i = 0; i < M; i++){
        cin >> oper;
        if(oper == "add"){
            cin >> x;
            S |= (1 << x);
        }
        else if(oper == "remove"){
            cin >> x;
            S &= ~(1 << x);
        }
        else if(oper == "check"){
            cin >> x;
            if(S & (1 << x)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(oper == "toggle"){
            cin >> x;
            S ^= (1 << x);
        }
        else if(oper == "all"){
            S = (1 << 21) - 1;
        }
        else if(oper == "empty"){
            S = 0;
        }
    }
    
    return 0;
}
