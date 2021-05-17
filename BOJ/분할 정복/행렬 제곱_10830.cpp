#include <iostream>
#include <cstring>
using namespace std;

int N;
long long B;

// ���� ����� �����ϴ� class
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
    
    // ������ �����ε��� ���ؼ� ����� ���� ����
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
    
    // ����� ���Ҹ� �����ִ� �Լ�
    void show(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << Map[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

// ���������� ���ؼ� �ŵ������� ���ش�
Matrix power(Matrix& M, long long b){
    
    if(b == 1) return M;
     
    // Ȧ���� ���� A^m�� A * A^(m-1) �� ������ �ȴ�
    if(b % 2) return power(M, b-1) * M;
    Matrix half = power(M, b/2);
    
    return half * half;
}

int main(){
    
    cin >> N >> B;
    
    Matrix M1(N);
    //result ����� M1�� B������ ��ķ� �ʱ�ȭ ���ش�
    Matrix result = power(M1, B);
    result.show();
    
    return 0;
}
