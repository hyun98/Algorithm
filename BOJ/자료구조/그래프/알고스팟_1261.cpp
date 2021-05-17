#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, broke = 0, a = 0, b = 0;
vector< vector<int> > wall;
vector<pair<int, int>> grp;

void graph(int x, int y, int z){
    int w = 0, r = 0, c = 0;
    while(r != M && c != N){
        if(r+1 <= M && ){

        }
    }





    for(r = 0; r < N; r++){
        if(wall[r][c] == 1){
            broke++;
        }
    }
    for(c = 0; c < M; c++){
        if(wall[r][c] == 1){
            broke++;
        }
    }
}

void solve(){
    while(true){
        graph(0, 0, N*M);
    }
}

void input(){
    cin >> N >> M;
    vector<int> temp;
    int t;
    for(int i = 0; i < M; i++){
        cin >> t;
        temp.push_back(t);
    }
    for(int i = 0; i < M; i++){
        int a = temp[i];
        vector<int> inner;
        while(a != 0){
            inner.push_back(a%10);
            a/=10;
        }
        reverse(inner.begin(), inner.end());
        wall.push_back(inner);
    }
}

int main(){


    return 0;
}
