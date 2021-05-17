#include <iostream>
#include <vector>

#define INF 99999999

using namespace std;

string Switch[10] = { "***.............",
                      "...*...*.*.*....",
                      "....*.....*...**",
                      "*...****........",
                      "......***.*.*...",
                      "*.*...........**",
                      "...*..........**",
                      "....**.*......**",
                      ".*****..........",
                      "...***...*...*.."
                    };

vector<int> Time;

class Clock{

public:
    bool check_Time(){
        for(int i = 0; i < 16; i++){
            if(Time[i] % 4 == 0) continue;
            else return false;
        }
        return true;
    }

    void push_switch(int now){
        for(int i = 0; i < 16; i++){
            if(Switch[now][i] == '*') Time[i] += 1;
        }
    }

    int set_Time(int now){
        if(10 == now){

            if(check_Time()) return 0;
            else return INF;
        }

        int temp = INF;
        // 한 스위치당 3번까지 누를 수 있음 -> 4번 이상 누르면 그대로이기 때문
        for(int i = 0; i < 4; i++){
            temp = min(temp, i + set_Time(now+1));
            push_switch(now);
        }

        return temp;
    }


    void input_Time(){
        int t;
        for(int i = 0; i < 16; i++){
            cin >> t;
            switch(t){
                case 3: Time[i] = 1; break;
                case 6: Time[i] = 2; break;
                case 9: Time[i] = 3; break;
                case 12: Time[i] = 0; break;
                default: break;
            }
        }
    }
};

int main(){
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        Time.resize(16, 0);
        Clock t1;
        t1.input_Time();
        int a = t1.set_Time(0);
        if(a == INF) cout << "-1\n";
        else cout << a << endl;
        Time.clear();
    }
    return 0;
}
