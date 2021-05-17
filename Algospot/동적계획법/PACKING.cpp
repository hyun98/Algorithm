#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;

struct Item{
    string name;
    int volume, needs;
};

class Pack{
    int N, W, dp[101][1001], i_num = 0;
    vector<Item> item_list;
    deque<string> rem;
    
public:
    Pack(){
        string name;
        int vol, need;
        cin >> N >> W;
        item_list.push_back({"", 0, 0});
        for(int i = 1; i <= N; i++){
            Item temp;
            cin >> temp.name >> temp.volume >> temp.needs;
            item_list.push_back(temp);
        }
        memset(dp, 0, sizeof(dp));
    }
    
    void solve(){
        //bottom-up
        for(int i = 1; i <= N; i++){
            int now_item_need = item_list[i].needs;
            int now_item_vol = item_list[i].volume;
            for(int v = 0; v <= W; v++){
                if(now_item_vol > v) dp[i][v] = dp[i-1][v];
                else dp[i][v] = max(dp[i-1][v], (dp[i-1][v-now_item_vol] + now_item_need));
            }
        }
        
        find_union(dp[N][W]);
        cout << dp[N][W] << " " << i_num << "\n";
        for(auto w : rem){
            cout << w << "\n";
        }
    }
    
    void find_union(int ans){
        bool cut = false;
        for(int i = 1; i <= N; i++){
            for(int j = 0; j <= W; j++){
                if(dp[i][j] == ans){
                    i_num++;
                    rem.push_front(item_list[i].name);
                    ans -= item_list[i].needs;
                    cut = true;
                    break;
                }
            }
            if(cut) break;
        }
        if(ans == 0) return;
        
        find_union(ans);
    }
    
//    int pack(int left_vol, int now_item){
//        // top-down
//        
//    }
};

int main(){
    int test;
    cin >> test;
    while(test--){
        Pack P1;
        P1.solve();
    }
    return 0;
}
