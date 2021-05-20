#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2e11+7
using namespace std;

int N;
int res[3];
vector<long long> arr;

// O(n^2) 같은데 
void solution(){
    
    long long temp, result = INF;
    
    // 한 원소를 피벗으로
    for(int pivot = 0; pivot < arr.size()-2; pivot++){
        int lo = pivot + 1;
        int hi = N-1;
    
        while(lo < hi){
            temp = arr[pivot] + arr[lo] + arr[hi];
            if(abs(temp) < result){
                result = abs(temp);
                res[0] = pivot;
                res[1] = lo;
                res[2] = hi;
            }
            
            long long left = arr[pivot] + arr[lo+1] + arr[hi];
            long long right = arr[pivot] + arr[lo] + arr[hi-1];
            
            if(abs(left) < abs(right)) lo++;
            else hi--;
        }
    }
    
    cout << arr[res[0]] << " " << arr[res[1]] << " " << arr[res[2]];
}

void input(){
    cin >> N;
    long long a;
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
