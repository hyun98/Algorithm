#include <iostream>
#include <vector>
using namespace std;

int main(){
    int C, N, L, a;
    cin >> C;
    while(C--){
        vector<int> cost;
        double result = 99999;
        cin >> N >> L;
        for(int i = 0; i < N; i++){
            cin >> a;
            cost.push_back(a);
        }

        while(L <= N){
            int sum = 0;
            int i = 0;
            while(i + L <= N){
                for(int j = i; j < i + L; j++){
                    if(i + L > N) break;
                    sum += cost[j];
                }
                if(double(sum)/double(L) < result){
                    result = double(sum)/double(L);
                }
                i++;
            }
            L++;
        }
        printf("%.8lf\n", result);
    }
    return 0;
}
