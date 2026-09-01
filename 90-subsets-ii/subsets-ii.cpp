class Solution {
public:
   void f ( vector<int>&nums , int i , int n , vector<int>store , set<vector<int>>&st ) {
      if ( i == n ) {
         st.insert(store);
         return;
      }
      store.push_back(nums[i]);
      f ( nums , i + 1 , n , store , st );
      store.pop_back();
      f ( nums , i + 1 , n , store , st );
      store.pop_back();
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         int n = nums.size();
         sort(nums.begin(),nums.end());
         vector<int>store;
         set<vector<int>>st;
         f ( nums , 0 , n , store , st );
         return vector<vector<int>>(st.begin(),st.end());
    }
};