#include <iostream>

using namespace std;

int N;
int nums[500001];
int temp[500001];

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }
}

long long mergesort(int st, int ed){
    if(st == ed) return 0;
    int mid = (st + ed)/2;
    
    long long result = mergesort(st, mid) + mergesort(mid+1, ed);
    
    int lo = st;
    int hi = mid+1;
    int idx = 0;
    
    while(lo <= mid || hi <= ed){
        // 변화가 없는 경우
        if(lo <= mid && (hi == ed + 1 || nums[lo] <= nums[hi])){
            temp[idx++] = nums[lo++];
        }
        // hi쪽 원소가 lo쪽 원소보다 작다면 옮겨준다
        else{
            result += (long long)(mid + 1 - lo);
            temp[idx++] = nums[hi++];
        }
    }
    
    for(int i = st; i <= ed; i++){
        nums[i] = temp[i - st];
    }
    
    return result;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    
    cout << mergesort(0, N-1);
    
    return 0;
}