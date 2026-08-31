class Solution {
public:
    int findLastPos ( vector<int>& nums, int n , int target ) {
        int low = 0 , high = n - 1;
        int ans = -1;
        while ( low <= high ) {
            int mid = low - ( low - high ) / 2;
            if ( nums[mid] == target ) {
                ans = mid;
                low = mid + 1;
            }
            else if ( nums[mid] < target ) {
                low = mid + 1;
            }
            else  {
                high = mid - 1;
            }
        }
        return ans;
    }
    int findFirstPos ( vector<int>& nums, int n , int target ) {
        int low = 0 , high = n - 1;
        int ans = -1;
        while ( low <= high ) {
            int mid = low - ( low - high ) / 2;
            if ( nums[mid] == target ) {
                ans = mid;
                high = mid - 1;
            }
            else if ( nums[mid] > target ) {
                high = mid - 1;
            }
            else  {
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int firstPos = findFirstPos ( nums , n , target );
        int lastPos = findLastPos ( nums , n , target );
        return {firstPos,lastPos};
    }
};        