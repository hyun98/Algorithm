#include <iostream>
#include <cmath>

using namespace std;

int side[3];
int N;
int cube[21];
int use_block = 0;

void init(){
    int a, b;
    cin >> side[0] >> side[1] >> side[2];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        cube[a] = b;
    }
}

void check(int s, int l, int w, int h){
    while(true){
        for()
    }
}

int DnC(int l, int w, int h){
    if(l == 0 || w == 0 || h == 0) return 0;
    int s = min(l, w);
    int s = min(s, h);
    int s = log2(s);
    
    while(s >= 0){
        if(!cube[s]) continue;
        int T = 1 << s;
        cube[s]--;
        return DnC(l-T, w, h) + DnC(l, w-T, h) + DnC(l, w, h-T) + 1;
    }
}

int main(){
    init();
    DnC(side[0], side[1], side[2]);
    return 0;
}
