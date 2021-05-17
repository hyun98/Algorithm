#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

struct V{
    vector<int> townlink;
};

class Prison{
    int N, D, P, T;
    double dp[51][101];
    vector<V> town;
    vector<int> Q;
    
public:
    Prison(){
        int x;
        cin >> N >> D >> P;
        V temp;
        town.resize(N+1, temp);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> x;
                if(x) town[i].townlink.push_back(j);
            }
        }
        cin >> T;
        Q.resize(T, 0);
        for(int i = 0; i < T; i++){
            cin >> Q[i];
        }
        memset(dp, -1.0, sizeof(dp));
    }
    
    void solve(){
        setprecision(11);
        for(int i = 0; i < Q.size(); i++){
            
            cout <<setprecision(10)<< Search(Q[i], D) << "\n";
        }
        cout << endl;
    }
    
    // day일 째에  dest 마을에 숨어있을 확률
    double Search(int dest, int day){
        if(day == 0) return (dest == P? 1.0 : 0.0);
        
        double &ret = dp[dest][day];
        if(ret > -0.5) return ret;
        ret = 0.0;
        
        for(int i = 0; i < town[dest].townlink.size(); i++){
//            cout <<"dest : "<<dest << "   next : " << town[dest].townlink[i] << "\n";
            int next = town[dest].townlink[i];
            ret += (Search(next, day-1)/town[next].townlink.size());
//            cout << "dest ret : " << ret << endl;
        }
        return ret;
    }
    
    
};

int main(){
    int test;
    cin >> test;
    while(test--){
        Prison P1;
        P1.solve();
    }
    return 0;
}
