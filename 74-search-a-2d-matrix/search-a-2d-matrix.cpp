class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target >= matrix[mid][0] && target <= matrix[mid][m - 1]) {
                int l = 0, r = m - 1;
                while (l <= r) {
                    int cMid = l + (r - l) / 2;
                    if (matrix[mid][cMid] == target) return true;
                    if (matrix[mid][cMid] < target) l = cMid + 1;
                    else r = cMid - 1;
                }
                return false;
            }
            
            else if (target < matrix[mid][0]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return false;
    }
};