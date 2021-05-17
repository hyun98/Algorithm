#include <iostream>

using namespace std;

int N;
int arr[100005];

inline void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
}

long long divide(int st, int ed){
    if(st == ed) return (long long)arr[st] * arr[st];
    
    int mid = (st + ed) >> 1;
    
    long long result = max(divide(st, mid), divide(mid+1, ed));
    
    int lo = mid;
    int hi = mid+1;
    int min_val = min(arr[lo], arr[hi]);
    long long psum = arr[lo] + arr[hi];
    
    result = max(result, min_val * psum);
    
    while(st < lo || hi < ed){
        //왼쪽 증가
        if((arr[lo-1] >= arr[hi+1] || hi == ed) && st < lo){
            lo--;
            min_val = min(min_val, arr[lo]);
            psum += arr[lo];
        }
        // 오른쪽 증가
        else{
            hi++;
            min_val = min(arr[hi], min_val);
            psum += arr[hi];
        }
        
        result = max(result, min_val * psum);
    }
    
    return result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    cout << divide(0, N-1);
    
    return 0;
}
