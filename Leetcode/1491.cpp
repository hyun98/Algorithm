class Solution {
public:
    double average(vector<int>& salary) {
        double ret = 0;
        
        sort(salary.begin(), salary.end());
        for(int i = 1; i < salary.size()-1; i++){
            ret += (double)salary[i];
        }
        
        ret /= (double)(salary.size()-2);
        
        return ret;
    }
};