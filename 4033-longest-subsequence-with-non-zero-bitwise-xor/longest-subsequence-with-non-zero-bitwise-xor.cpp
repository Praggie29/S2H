class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total=0;
        for(int num:nums){
            total^=num;
        }
        if(total!=0){
            return nums.size();
        }
        bool all=true;
        for(int num:nums){
            if(num!=0){
                all=false;
                break;
            }
        }
        if(all) return 0;
        return nums.size()-1;
    }
};