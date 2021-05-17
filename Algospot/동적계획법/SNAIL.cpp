#include <iostream>
#include <cmath>

using namespace std;

class Snail{
    int height, day;
    static double dp[1001][2001];
    
public:
    Snail(){
        cin >> height >> day;
        set_dp();
    }
    
    void set_dp(){
        for (int d = 0; d < 1001; d++){
           for (int h = 0; h < 2001; h++){
              dp[d][h] = -1.0;
            }
        }
    }
    
    double climb(int days, int climbed){
        if(days == day) return climbed >= height? 1 : 0;
        
        double &ret = dp[days][climbed];
        if(ret != -1) return ret;
        
        return ret = 0.25 * climb(days+1, climbed+1) + 0.75 * climb(days+1, climbed+2);
    }
//    void print(){
//        for(int i = 0; i < day; i++){
//            for(int j = 0; j < i*2+1; j++){
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }
//    }
};

double Snail::dp[1001][2001] = {0, };

int main(){
    int test;
    cin >> test;
    while(test--){
        Snail dalpeng;
        cout.precision(11);
        cout << dalpeng.climb(0, 0) <<endl;
//        dalpeng.print();
    }
    return 0;
}
