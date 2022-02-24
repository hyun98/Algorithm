#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Map[1001][1001];

void down(int &r, int &c, int &i, int n){
    cout << "down\n";
    while(!Map[r][c] && r < n){
        cout << r << ", " << c << " : " << i << '\n';
        Map[r][c] = i++;
        r++;
    }
    r--;
}

void rt(int &r, int &c, int &i, int n){
    cout << "right\n";
    while(!Map[r][c] && c < n){
        cout << r << ", " << c << " : " << i << '\n';
        Map[r][c] = i++;
        c++;
    }
    c--;
}

void up(int &r, int &c, int &i, int n){
    cout << "up\n";
    while(!Map[r][c]){
        cout << r << ", " << c << " : " << i << '\n';
        Map[r][c] = i++;
        r--;
        c--;
    }
    r++;
    c++;
}

vector<int> solution(int n) {
    vector<int> answer;
    
    int i = 1;
    int r = 0;
    int c = 0;
    
    while(true){
        down(r, c, i, n);
        cout << Map[r][c+1] << '\n';
        if(Map[r][++c]) break;
        rt(r, c, i, n);
        if(Map[--r][--c]) break;
        up(r, c, i, n);
        if(Map[++r][c]) break;
    }
    
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            if(Map[i][j]) answer.push_back(Map[i][j]);
            else break;
        }
    }
    
    
    return answer;
}

int main(){
    solution(4);
    return 0;
}