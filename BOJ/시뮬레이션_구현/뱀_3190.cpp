#include <bits/stdc++.h>

using namespace std;
                                    //첫 번째 정수는 행, 두 번째 정수는 열 위치를 의미사과의 위치는 모두 다르며,
                                    //맨 위 맨 좌측 (1행 1열) 에는 사과가 없다.
int Board[110][110] = {0, };
vector<pair<int, char>> s_move; //왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다
int N, K, L, t = 0;

class Snake{
    vector<pair<int, int>> snake_;  //뱀의 좌표들
    string direct;
public:
    Snake() : direct("right"){
        snake_.push_back(make_pair(1,1));
    }
    void turn(char d){
        if(d == 'D'){
            if(direct == "right"){
                direct = "bottom";
            }
            else if(direct == "bottom"){
                direct = "left";
            }
            else if(direct == "left"){
                direct = "top";
            }
            else{
                direct = "right";
            }
        }
        else{
            if(direct == "right"){
                direct = "top";
            }
            else if(direct == "bottom"){
                direct = "right";
            }
            else if(direct == "left"){
                direct = "bottom";
            }
            else{
                direct = "left";
            }
        }
    }
    void go(){  //머리만 앞으로 감
        if(direct == "top"){
            snake_.insert(snake_.begin(), make_pair(snake_[0].first-1, snake_[0].second));
        }
        else if(direct == "right"){
            snake_.insert(snake_.begin(), make_pair(snake_[0].first, snake_[0].second+1));
        }
        else if(direct == "left"){
            snake_.insert(snake_.begin(), make_pair(snake_[0].first, snake_[0].second-1));
        }
        else if(direct == "bottom"){
            snake_.insert(snake_.begin(), make_pair(snake_[0].first+1, snake_[0].second));
        }
    }
    void tail_pop(){
        if(Board[snake_[0].first][snake_[0].second] == 1){
            snake_.pop_back();
        }
    }
    int bump(){    //지 몸에 부딪힐 때, 머리가 벽에 부딪힐 때
        if(find(snake_.begin()+1, snake_.end(), snake_[0]) != snake_.end()){return 1;}
        else if(Board[snake_[0].first][snake_[0].second] == 0){return 1;}
        else{
            return 0;
        }
    }
    void print(){
        cout << snake_[0].first << " " << snake_[0].second << "\n";
    }
};

void snake_move(Snake s){
    int moved = 0;
    int prev = 0;
    int X;
    while(true){
        if(moved > s_move.size()){
            X = 1000000;
        }
        else{
            X = s_move[moved].first;
            if(prev != 0){X = s_move[moved].first - prev;}
            prev = s_move[moved].first;
        }
        while(X > 0){
            s.go();
            t++;
            if(s.bump()){
                cout << t;
                return;
            }
            s.print();
            s.tail_pop();//사과가 없으면 발동
//            cout << "t = " << t << endl;
//            cout << s_move[moved].first << " "<< s_move[moved].second << "\n";
            X--;
        }
        if(s_move[moved].second == 'D'){
            s.turn('D');
        }
        else{
            s.turn('L');
        }
        cout <<"회전완료" << endl;
        moved++;
    }
}

int main(){
    cin >> N;
    for(int row = 1; row <= N; row++){
        for(int col = 1; col <= N; col++){
            Board[row][col] = 1;
        }
    }
//    for(int i = 0; i <= N; i++){
//        for(int j = 0; j <= N; j++){
//            cout << Board[i][j] << " ";
//        }
//        cout << "\n";
//    }
    cin >> K;
    for(int i = 0; i < K; i++){
        int row, col;
        cin >> row >> col;
        Board[row][col] = 2;    //사과 존재
    }
    for(int i = 0; i <= N+1; i++){
        for(int j = 0; j <= N+1; j++){
            cout << Board[i][j] << " ";
        }
        cout << "\n";
    }
    cin >> L;
    for(int i = 0; i < L; i++){
        int X;
        char C;
        cin >> X >> C;
        s_move.push_back(make_pair(X, C));
    }
    Snake baam;
    snake_move(baam);

    return 0;
}
