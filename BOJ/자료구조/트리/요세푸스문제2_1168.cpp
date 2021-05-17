#include <iostream>
#include <list>
using namespace std;

list<int> table;
int N, K;
//¹Ì¿Ï
void solve(){
    int t_size = table.size(), ltr = 0;

    cout << "<";

    while(t_size > 0){
        if(t_size == 1){
            cout << *table.begin() << ">";
            return;
        }

        cout << *(table.begin() + ltr) << ", ";
        table.erase(table.begin() + ltr);
        t_size--;
        if(ltr == t_size){
            ltr = 0;
        }

        ltr += K%t_size;
        if(ltr >= t_size){
            ltr -= t_size;
        }
    }
}

int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        table.push_back(i);
    }
    solve();
    return 0;
}

