#include <iostream>
#include <cstring>

#define MIN(a,b) (a<b ? a : b)
using namespace std;

int button[10] = {1,1,1,1,1,1,1,1,1,1};
int channel, M, min_cnt = 1e9;

void init(){
    cin >> channel >> M;
    int broke;
    for(int i = 0; i < M; i++){
        cin >> broke;
        button[broke] = 0;
    }
    min_cnt = MIN(min_cnt, abs(100 - channel));
}


void find_pressnum(string num){
    for(int i = 0; i < 10; i++){
        if(!button[i]) continue;
        
        string temp = num + to_string(i);
        
        min_cnt = MIN(min_cnt, abs(channel - stoi(temp)) + temp.length());
        
        if(temp.length() < 6){
            find_pressnum(temp);
        }
    }
}

int main(){
    init();
    if(M < 10) find_pressnum("");
    
    cout << min_cnt;
    return 0;
}
