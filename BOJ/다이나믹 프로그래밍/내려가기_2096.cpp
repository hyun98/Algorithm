#include <iostream>

#define GET_MIN(x,y,z) ((min(x, y))<(z)?(min(x, y)):(z))
#define GET_MAX(x,y,z) (max(x, y)>z?max(x, y):z)

using namespace std;


int N, score;
int Score_set[2][3], Max_score[2][3], Min_score[2][3];
int dc[3] = {1, 0, -1};

void sliding(){
    for(int i = 0; i < 3; i++){
        cin >> Score_set[0][i];
        Max_score[0][i] = Min_score[0][i] = Score_set[0][i];
    }
    
    for(int row = 1; row < N; row++){
        for(int col = 0; col < 3; col++){
            cin >> Score_set[1][col];
        }
        
        for(int i = 0; i < 3; i++){
            if(i == 0 || i == 2){
                Max_score[1][i] = max(Max_score[0][i] + Score_set[1][i], Max_score[0][i+dc[i]] + Score_set[1][i]);
                Min_score[1][i] = min(Min_score[0][i] + Score_set[1][i], Min_score[0][i+dc[i]] + Score_set[1][i]);
            }
            else if(i == 1){
                Max_score[1][i] = GET_MAX(Max_score[0][i-1] + Score_set[1][i], Max_score[0][i] + Score_set[1][i], Max_score[0][i+1] + Score_set[1][i]);
                Min_score[1][i] = GET_MIN(Min_score[0][i-1] + Score_set[1][i], Min_score[0][i] + Score_set[1][i], Min_score[0][i+1] + Score_set[1][i]);
                
            }
        }
        // sliding window 
        for(int i = 0; i < 3; i++){
            Max_score[0][i] = Max_score[1][i];
            Min_score[0][i] = Min_score[1][i];
            Score_set[0][i] = Score_set[1][i];
        }
    }
    
    int min_result = 9999999, max_result = 0;
    for(int i = 0; i < 3; i++){
        max_result = max(max_result, Max_score[0][i]);
        min_result = min(min_result, Min_score[0][i]);
    }
    cout << max_result << " " << min_result;
}

int main(){
    cin >> N;
    sliding();
    
    return 0;
}
