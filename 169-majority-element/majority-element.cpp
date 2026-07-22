class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if ( n == 1 ) return nums[0];
        int cnt = 1;
        sort(nums.begin(),nums.end());
         int ele = nums[0];
        for ( int i = 1 ; i < n ; i ++ ) {
            if ( ele == nums[i] ) {
                cnt ++;
            }
            else {
                cnt = 1;
                ele = nums[i];
            }
             if ( cnt > n / 2 ) return ele;
        }
       
        return -1;
    }
};