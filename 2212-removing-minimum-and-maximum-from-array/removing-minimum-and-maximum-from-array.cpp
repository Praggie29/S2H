class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int maxIdx;
        int mini = INT_MAX;
        int minIdx;
        int minDeletions = INT_MAX;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( nums[i] < mini ) {
                mini = nums[i];
                minIdx = i;
            }
            if ( nums[i] > maxi ) {
                maxi = nums[i];
                maxIdx = i;
            }
        }
        minDeletions = min(minDeletions, max(maxIdx + 1, minIdx + 1));
        minDeletions = min(minDeletions, max(n - maxIdx, n - minIdx));
        minDeletions = min(minDeletions, (maxIdx + 1) + (n - minIdx));
        minDeletions = min(minDeletions, (minIdx + 1) + (n - maxIdx));
        return minDeletions;
    }
};