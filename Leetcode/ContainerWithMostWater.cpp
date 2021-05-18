class Solution {
public:
    int maxArea(vector<int>& height) {
        int st = 0;
        int ed = height.size()-1;
        int result = 0;
        
        while(st < ed){
            result = max(result, (ed-st) * min(height[st], height[ed]));
            if(height[st] < height[ed]){
                st+=1;
            }
            else{
                ed-=1;
            }
        }
        return result;
    }
};