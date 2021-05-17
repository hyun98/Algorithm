#include <iostream>
#include <cstring>
using namespace std;

class PI{
    string pi;
    int dp[10001];
public:
    PI(){
        cin >> pi;
        memset(dp, -1, sizeof(dp));
    }

    int Difficulty(string subpi){
//        cout << subpi << endl;
        //��� ���ڰ� ���� ��
        if(subpi == string(subpi.size(), subpi[0])) return 1;

        //���ڰ� ������ 1�� ������ ������ ��
        bool updown = true;
        int a = subpi[0] - '0';
        int cnt = 1;
        for(int i = 0; i < subpi.size()-1; i++){
            if(subpi[i+1] - subpi[i] != subpi[1] - subpi[0]){
                updown = false;
            }
        }
        if(updown && abs(subpi[1] - subpi[0]) == 1) return 2;

        //�� ���� �����Ƽ� ���� ��
        bool alter = true;
        for(int i = 0; i < subpi.size(); i++){
            if(subpi[i] != subpi[i%2]) alter = false;
        }
        if(alter) return 4;

        // ���������� �̷� ��(���� 1�ƴ�)
        if(updown) return 5;

        //������ ���
        return 10;
    }
    
    int memo(int beg){
        
        if(beg == pi.size()) return 0;
        
        int &ret = dp[beg];
        if(ret != -1) return ret;
        
        ret = 99999999;

        for(int L = 3; L <= 5; L++){
            if(beg+L <= pi.size()){
                ret = min(ret, memo(beg+L) + Difficulty(pi.substr(beg, L)));
            }
        }
        return ret;
    }
    
};

int main(){
    int test;
    cin >> test;
    while(test--){
        PI api;
        cout << api.memo(0) << endl;
    }
    return 0;
}
