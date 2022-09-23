#include <string>
#include <vector>

using namespace std;


// 징검다리를 건너야 하는 니니즈 친구들의 수는 무제한 이라고 간주합니다.
// stones 배열의 크기는 1 이상 200,000 이하입니다.
// stones 배열 각 원소들의 값은 1 이상 200,000,000 이하인 자연수입니다.
// k는 1 이상 stones의 길이 이하인 자연수입니다.

int INF = 200000000;

int solution(vector<int> stones, int allow) {
    int answer = 0;
    
    int lo = 1;
    int hi = INF;
    
    while(lo <= hi){
        
        int mid = (lo + hi) / 2;
        
        int sequence = 0;
        int maxGap = 0;
        
        for(int i = 0; i < stones.size(); i++){
            if(stones[i] > mid){
                sequence = 0;
            }
            else{
                sequence++;
                maxGap = max(maxGap, sequence);
            }
        }
        
        if(maxGap < allow){
            lo = mid + 1;
            answer = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    
    return lo;
}