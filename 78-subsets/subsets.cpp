class Solution {
public:
   void f ( vector<int>&nums , int i , int n , vector<int>store , vector<vector<int>>&ans ) {
      if ( i == n ) {
         ans.push_back(store);
         return;
      }
      store.push_back(nums[i]);
      f ( nums , i + 1 , n , store , ans );
      store.pop_back();
      f ( nums , i + 1 , n , store , ans );
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>store;
        f ( nums , 0 , n , store , ans );
        return ans;
    }
};