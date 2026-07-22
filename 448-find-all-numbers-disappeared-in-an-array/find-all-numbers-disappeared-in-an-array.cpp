class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>missingNums;
        unordered_set<int>st;
        for ( int i = 0 ; i < n ; i ++ ) {
            st.insert(nums[i]);
        }
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( st.count(i) ) continue;
            else missingNums.push_back(i);
        }
        return missingNums;
    }
};