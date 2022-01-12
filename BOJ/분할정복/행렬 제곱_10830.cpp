#include <iostream>
#include <cstring>
using namespace std;

int N;
long long B;

// 정방 행렬을 저장하는 class
class Matrix{

public:
    int Map[6][6];
    
    Matrix(){}
    Matrix(int n){
        int in;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> in;
                Map[i][j] = in % 1000;
            }
        }
    }
    
    // 연산자 오버로딩을 통해서 행렬의 곱셈 구현
    Matrix operator* (Matrix& m){
        Matrix temp;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                temp.Map[i][j] = 0;
                for(int k = 0; k < N; k++){
                    temp.Map[i][j] += ((this->Map[i][k] * m.Map[k][j]) % 1000);
                    temp.Map[i][j] %= 1000;
                }
            }
        }
        
        return temp;
    }
    
    // 행렬의 원소를 보여주는 함수
    void show(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << Map[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

// 분할정복을 통해서 거듭제곱을 해준다
Matrix power(Matrix& M, long long b){
    
    if(b == 1) return M;
     
    // 홀수일 때는 A^m은 A * A^(m-1) 로 나뉘게 된다
    if(b % 2) return power(M, b-1) * M;
    Matrix half = power(M, b/2);
    
    return half * half;
}

int main(){
    
    cin >> N >> B;
    
    Matrix M1(N);
    //result 행렬을 M1을 B제곱한 행렬로 초기화 해준다
    Matrix result = power(M1, B);
    result.show();
    
    return 0;
}
