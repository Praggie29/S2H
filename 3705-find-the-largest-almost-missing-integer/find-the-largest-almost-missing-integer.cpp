class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int,int> mpp;
        int maxiEle = INT_MIN;
        for ( int i = 0 ; i + k <= n  ; i ++ ) {
            unordered_set<int> unique_in_window;
            int j = i;
            int s = k;
            while (s-- ) {
              unique_in_window.insert(nums[j]);
              j++;
            }
            for (int num : unique_in_window) {
                mpp[num]++;
            }
        }
        for ( auto &it : mpp ) {
            if ( it.second == 1 ) {
                maxiEle = max ( maxiEle , it.first );
            }
        }
        return maxiEle == INT_MIN ? -1 : maxiEle;
    }
};