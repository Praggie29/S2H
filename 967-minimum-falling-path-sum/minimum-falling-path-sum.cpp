class Solution {
public:
    int f (int i , int j , vector<vector<int>>& matrix , vector<vector<int>>& dp ) {
        int n = matrix.size();
        if ( i >= n || j >= n || j < 0 ) return 1e9;
        if ( i == n - 1 ) return matrix[i][j];
        if ( dp[i][j] != -1e9 ) return dp[i][j];
        int nextRow = matrix[i][j] + f ( i + 1 , j , matrix , dp );
        int diagonalLeft = matrix[i][j] + f ( i + 1 , j - 1 , matrix , dp );
        int diagonalRight = matrix[i][j] + f ( i + 1 , j + 1 , matrix , dp );
        return dp[i][j] = min ( {nextRow , diagonalLeft , diagonalRight} );
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1e9));
        int mini = INT_MAX;
    
            for ( int j = 0 ; j < n ; j ++ ) {
                mini = min ( mini , f ( 0 , j , matrix , dp ) );
            }
        
        return mini;
    }
};