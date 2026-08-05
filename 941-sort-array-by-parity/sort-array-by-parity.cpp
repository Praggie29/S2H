class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        if ( n <= 1 ) return nums;
        int i = 0 , j = 1;
        while ( i < j && j < n ) {
             if ( nums[i] % 2 != 0 && nums[j] % 2 != 0 ) {
                j++;
            }
            else if ( nums[i] % 2 != 0 && nums[j] % 2 == 0 ) {
                swap ( nums[i] , nums[j]);
                j++;
                i++;
            }
            else if ( nums[i] % 2 == 0 && nums[j] % 2 != 0 ) {
                i++;
                j++;
            }
            else {
                i++;
                j++;
            }
        }
        return nums;
    }
};