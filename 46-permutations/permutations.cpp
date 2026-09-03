class Solution {
public:
    void f ( vector<int>&nums , vector<vector<int>>&ans , vector<int>&store , vector<int>& freq ) {
        if ( store.size() == nums.size() ) {
            ans.push_back(store);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i ++ ) {
            if (!freq[i]) {
                freq[i] = 1;
                store.push_back(nums[i]);
                f ( nums , ans , store , freq );
                freq[i] = 0;
                store.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>store;
        vector<int> freq(n, 0);
        f(nums,ans,store,freq);
        return ans;
    }
};