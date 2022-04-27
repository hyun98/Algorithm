class Solution {
public:
    int countOdds(int low, int high) {
        // low 와 high 사이의 홀수의 개수는?
        int temp = high - low + 1;
        int ret = 0;
        if(temp % 2 == 0){
            ret = temp / 2;
        }
        else{
            if(low % 2 && high % 2){
                ret = temp / 2 + 1;
            }
            else{
                ret = temp / 2;
            }
        }
        
        return ret;
    }
};
