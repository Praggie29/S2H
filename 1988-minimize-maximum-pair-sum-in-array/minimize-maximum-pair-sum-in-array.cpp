class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = n - 1;
        sort ( nums.begin(),nums.end() );
        int ans = INT_MIN;
        while ( i < j ) {
            int sum = nums[i] + nums[j];
            ans = max ( ans , sum );
            i ++;
            j --;
        }
        return ans;
    }
};