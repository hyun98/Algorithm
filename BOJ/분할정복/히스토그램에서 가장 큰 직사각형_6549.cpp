#include <iostream>

#define MAX(a, b) (((a) >= (b)) ? (a) : (b))
#define MIN(a, b) (((a) <= (b)) ? (a) : (b))
using namespace std;

// 분할정복
class histo{
    int n;
    int heights[100001];
    
public:
    histo(int n) : n(n){
        for(int i = 0; i < n; i++){
            cin >> heights[i];
        }
    }
    
    // 시작 인덱스부터 끝 인덱스
    long long divide_histo(int st, int ed){
        if(st == ed) return heights[st];
        
        int mid = (st+ed) / 2;
        
        //두 부분으로 나누어서 각각의 최대 넓이 중 큰 값을 결과값에 입력
        long long result = MAX(divide_histo(st, mid), divide_histo(mid+1, ed));
        
        long long new_height = MIN(heights[mid], heights[mid+1]);
        result = MAX(result, new_height * 2);
        
        int l = mid;
        int h = mid+1;

        // 항상 높이가 높은쪽으로 확장
        while(st < l || h < ed){
            if(st < l && (h == ed || heights[l-1] > heights[h+1])){
                l--;
                new_height = MIN(new_height, heights[l]);
            }
            else{
                h++;
                new_height = MIN(new_height, heights[h]);
            }
            result = MAX(result, new_height * (h-l+1));
        }
        
        return result;
    }
    
    void solve(){
        cout << divide_histo(0, n-1) << "\n";
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test;
    cin >> test;
    while(test){
        histo H1(test);
        H1.solve();
        cin >> test;
    }
    
    return 0;
}
