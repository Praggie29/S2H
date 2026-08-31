class Solution {
public:
    long long f ( vector<int>& nums, int threshold , int divisor ) {
        int count = 0;
        for ( int i = 0 ; i < nums.size() ; i ++ ) {
            count = count + (long long)(nums[i] + divisor - 1) / divisor;
        }
        return count;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = high;
        while ( low <= high ) {
            int mid = low + ( high - low ) / 2;
            if ( f ( nums , threshold , mid) <= threshold ) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};