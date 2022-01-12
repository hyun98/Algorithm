#include <iostream>
#include <string>

using namespace std;
int k, pixel[65][65];

void input_IMG(){
    string line;
    for(int i = 0; i < k; i++){
        cin >> line;
        for(int j = 0; j < line.length(); j++){
            pixel[i][j] = line[j] - '0';
        }
    }
}

void IMG_to_QTS(int k, int row, int col){
    if(k == 0) return;

    bool zero_img = false, one_img = false;
    for(int i = row; i < row + k; i++){
        for(int j = col; j < col + k; j++){
            if(pixel[i][j] == 0) zero_img = true;
            else one_img = true;
        }
    }
    if(zero_img && one_img){
        cout << "(";
        IMG_to_QTS(k/2, row, col);          //1
        IMG_to_QTS(k/2, row, col+k/2);      //2

        IMG_to_QTS(k/2, row+k/2, col);      //3
        IMG_to_QTS(k/2, row+k/2, col+k/2);  //4
        cout << ")";
    }
    else if(zero_img) cout << "0";
    else if(one_img) cout << "1";
}

int main(){
    cin >> k;

    input_IMG();
    IMG_to_QTS(k, 0, 0);

    return 0;
}
