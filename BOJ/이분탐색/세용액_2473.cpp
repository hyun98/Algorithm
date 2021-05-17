#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2e9+7
using namespace std;

int N;
long long res[3];
vector<int> arr;

// O(n^2) 같은데 
void solution(){
    // 한 원소를 피벗 원소로 두자
    int pivot = 0;
    int lo = 1;
    int hi = N-1;
    
    long long temp;
    
    while()
    
}

void input(){
    cin >> N;
    int a;
    for(int i = 0; i < N; i++){
        cin >> a;
        arr.push_back(a);
    }
    
    sort(arr.begin(), arr.end());
}

int main(){
    input();
    solution();
    
    return 0;
}
