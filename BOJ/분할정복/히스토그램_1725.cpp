#include <iostream>

#define Max_num 100001

using namespace std;

int N;
int heights[100001];

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> heights[i];
    }
}

int divide_histo(int st, int ed){
    if(st == ed) return heights[st];
    
    int mid = (st + ed) / 2;
    
    int result = max(divide_histo(st, mid), divide_histo(mid+1, ed));
    
    int lo = mid, hi = mid+1;
    int now_height = min(heights[lo], heights[hi]);
    
    result = max(result, 2*now_height);
    
    
    while(st < lo || hi < ed){
        if(hi == ed || heights[lo-1] > heights[hi+1]){
            lo--;
            now_height = min(now_height, heights[lo]);
        }
        else{
            hi++;
            now_height = min(now_height, heights[hi]);
        }
        
        result = max(result, now_height*(hi-lo+1));
    }
    
    return result;
}

int main(){
    input();
    cout << divide_histo(0, N-1);
    
    return 0;
}
