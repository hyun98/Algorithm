#include <iostream>

using namespace std;

int N;
int day[100001];

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> day[i];
    }
}

int divide(int st, int ed){
    if(st == ed) return day[st];
    
    int mid = (st + ed) / 2;
    
    int result = max(divide(st, mid), divide(mid+1, ed));
    
    int lo = mid;
    int hi = mid+1;
    int nh = min(day[lo], day[hi]);
    result = max(result, (hi - lo + 1) * nh);
    
    while(st < lo || hi < ed){
        if((day[lo-1] >= day[hi+1] || hi == ed) && st < lo){
            lo--;
            nh = min(nh, day[lo]);
        }
        else{
            hi++;
            nh = min(nh, day[hi]);
        }
        result = max(result, nh * (hi - lo + 1));
    }
    
    return result;
}

int main(){
    input();
    cout << divide(0, N-1);
    return 0;
}