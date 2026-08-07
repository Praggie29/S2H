class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minSizedSubArray = INT_MAX;
        int i = 0, j = 0;
        int subArraySum = 0; 
         while (j < n) {
            subArraySum += nums[j];
            if (subArraySum >= target) {
                minSizedSubArray = min(minSizedSubArray, j - i + 1);
                while ( subArraySum >= target ) {
                    subArraySum -= nums[i];
                     i++;
                    if (subArraySum >= target) minSizedSubArray = min(minSizedSubArray, j - i + 1);
                }
            }
            j++;
        }
        return minSizedSubArray == INT_MAX ? 0 : minSizedSubArray;
    }
};