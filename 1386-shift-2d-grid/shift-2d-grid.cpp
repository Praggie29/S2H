class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>ans;
        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < m ; j ++ ) {
                ans.push_back(grid[i][j]);
            }
        }
        
        int nn = ans.size();
        k = k % nn;
        reverse(ans.begin(),ans.end());
        reverse(ans.begin(),ans.begin()+k);
        reverse(ans.begin()+k,ans.end());
        vector<vector<int>>ans1(n,vector<int>(m,0));
        int idx = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < m ; j ++ ) {
                ans1[i][j] = ans[idx++];
            }
        }
        return ans1;
    }
};