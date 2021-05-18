#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

inline void che(int n, int not_primenum[]){
    for(int i = n+1; i < 4000; i++){
        if(i % n == 0) not_primenum[i] = 1;
    }
}

int solution(vector<int> nums) {
    int answer = 0, nums_len = nums.size();
    int not_primenum[4000];
    memset(not_primenum, 0, sizeof(not_primenum));
    for(int i = 2; i < 4000; i++){
        if(!not_primenum[i]) che(i, not_primenum);
    }
    
    for(int i = 0; i < nums_len-2; i++){
        for(int j = i+1; j < nums_len-1; j++){
            for(int k = j+1; k < nums_len; k++){
                if(!not_primenum[nums[i] + nums[j] + nums[k]]) answer++;
            }
        }
    }
    
    return answer;
}