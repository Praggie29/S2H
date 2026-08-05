class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n);
        vector<int>negValues,posValues;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( nums[i] > 0 ) {
               posValues.push_back(nums[i]);
            }
            else {
                negValues.push_back(nums[i]);
            }
        }
        int i = 0 , j = 0;
        for ( int k = 0 ; k < n ; k ++ ) {
            if ( k % 2 == 0 ) {
                ans[k] = posValues[i];
                i++;
            }
            else {
               ans[k] = negValues[j];
               j++;
            }
        }
        return ans;
    }
};