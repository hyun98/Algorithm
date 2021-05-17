//-----------------
//   아 못풀겠다 help
//-----------------
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct P{
    int r, c;
};

int row, col;
// 처음 호수의 상황; 0 : 얼음, 1 : 물
int Lake[1502][1502];
int testLake[1502][1502];
int MeltDate[1502][1502];
vector<int> Swan_r, Swan_c;
int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};


void input(){
    string line;
    cin >> row >> col;
    memset(MeltDate, 0, sizeof(MeltDate));
    memset(Lake, -1, sizeof(Lake));
    memset(testLake, -1, sizeof(Lake));
    for(int i = 1; i <= row; i++){
        cin >> line;
        for(int j = 1; j <= col; j++){
            if(line[j-1] == '.' || line[j-1] == 'L'){
                Lake[i][j] = 1;
                testLake[i][j] = 1;
                if(line[j-1] == 'L'){
                    Swan_r.push_back(i);
                    Swan_c.push_back(j);
                }
            }
            else{
                Lake[i][j] = 0;
                testLake[i][j] = 0;
            }
        }
    }
}

void make_daylake(){
    queue<P> que;
    int day = 1;
    
    //O(1500*1500)
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            if(Lake[i][j] == 1){
                if(Lake[i-1][j] == 0 || Lake[i+1][j] == 0 || 
                   Lake[i][j-1] == 0 || Lake[i][j+1] == 0){
                    P temp; temp.r = i; temp.c = j;
                    que.push(temp);
                }
            }
        }
    }
    
    while(!que.empty()){
        queue<P> q;
        while(!que.empty()){
            P temp;
            P next = que.front();
            que.pop();
            for(int i = 0; i < 4; i++){
                if(testLake[next.r + dr[i]][next.c + dc[i]] == 0){
                    if(MeltDate[next.r + dr[i]][next.c + dc[i]] == 0){
                        MeltDate[next.r + dr[i]][next.c + dc[i]] = day;
                        temp.r = next.r + dr[i]; temp.c = next.c + dc[i];
                        q.push(temp);
                        testLake[next.r + dr[i]][next.c + dc[i]] == 1;
                    }
                }
            }
        }
        
        day+=1;
        que = q;
    }
}

void showMeltDate(){
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            cout << MeltDate[i][j] <<" ";
        }
        cout << endl;
    }
}

int main(){
    input();
    make_daylake();
    showMeltDate();
    return 0;
}
