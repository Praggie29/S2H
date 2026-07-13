class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int totalNumOfEvenSizeNums = 0;
        int n = nums.size();
        for ( int i = 0 ; i < n ; i ++ ) {
            string num = to_string(nums[i]);
            int m = num.size();
            if ( m % 2 == 0 ) {
                totalNumOfEvenSizeNums++;
            }
        }
        return totalNumOfEvenSizeNums;
    }
};