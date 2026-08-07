class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int,int> mpp;
        int i = 0;
        while ( i < n ) {
            if ( mpp.find(nums[i]) != mpp.end() ) {
                int idx = mpp[nums[i]];
                if ( abs(i - idx) <= k ) return true;
                else mpp[nums[i]] = i;
            }
            else {
                mpp[nums[i]] = i;
            }
            i++;
        }
        return false;
    }
};