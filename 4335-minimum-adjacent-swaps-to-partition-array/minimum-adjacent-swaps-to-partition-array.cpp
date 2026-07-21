class Solution {
public:
   int m = 1e9 + 7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int numOfSmall = 0;
        int numOfMedium = 0;
        int numOfLarge = 0;
        long long ans = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( nums[i] < a ) {
                ans += ( numOfMedium + numOfLarge );
            }
            else if ( nums[i] >= a && nums[i] <= b ) {
                ans += numOfLarge;
                numOfMedium++;
            }
            else {
                numOfLarge++;
            }
        }
        return ans % m;
    }
};