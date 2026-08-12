class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map <int,int> mpp;
        int longestSubArray = INT_MIN;
        int i = 0 , j = 0;
        int n = nums.size();
        while ( j < n ) {
            mpp[nums[j]]++;
            while(mpp[nums[j]] > k) { 
                mpp[nums[i]]--;
                if ( mpp[nums[i]] == 0 ) mpp.erase(nums[i]);
                i++;
            }
            longestSubArray = max ( longestSubArray , j - i + 1 );
            j++;
        }
        return longestSubArray;
    }
};