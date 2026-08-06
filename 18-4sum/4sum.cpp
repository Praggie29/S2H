class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort (nums.begin(),nums.end());
        set<vector<int>>st;
        for ( int i = 0 ; i < n - 3 ; i ++ ) {
            for ( int k = n - 1 ; k > 1 ; k -- ) {
                int j = i + 1;
                int l = k - 1;
                while ( j < l ) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[k];
                    if ( sum == target ) {
                        st.insert({nums[i],nums[j],nums[l],nums[k]});
                        j++;
                        l--;
                    }
                    else if ( sum > target ) {
                        l--;
                    }
                    else {
                        j++;
                    }
                }
            }
        }
        return vector<vector<int>>(st.begin(),st.end());
    }
};