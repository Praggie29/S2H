class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map <int,int> mpp;
        for ( int i : nums ) mpp[i]++;
        int sum = nums[0];
        for ( int i = 1 ; i < nums.size() ; i ++ ) {
            if ( nums[i] - nums[i-1] == 1 ) sum += nums[i];
            else break;
        }
        
        while (mpp.find(sum) != mpp.end()) {
                sum++;
            }
            
        return sum;
    }
};