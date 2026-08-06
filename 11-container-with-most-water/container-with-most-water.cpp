class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAccumulatedWater = INT_MIN;
        int n = height.size();
        int l = 0 , r = n - 1;
        while ( l < r ) {
            if ( height[l] < height[r] ) {
                maxAccumulatedWater = max ( maxAccumulatedWater , height[l] * ( r - l ));
                l++;
            }
            else {
               maxAccumulatedWater = max ( maxAccumulatedWater , height[r] * ( r - l ));
                r--; 
            }
        }
        return maxAccumulatedWater;
    }
};