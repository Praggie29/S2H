class Solution {
public:
   bool canPlace(int row, int col, vector<string>& board, int n) {
    // Check left in the same row
    for (int j = col; j >= 0; j--) {
        if (board[row][j] == 'Q') return false;
    }
    
    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    
    // Check lower-left diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 'Q') return false;
    }
    
    return true;
}
    void solve (int col , vector<string>&board , vector<vector<string>>&ans , int n ) {
       if ( col == n ) {
          ans.push_back(board);
          return;
       }
       for ( int row = 0 ; row < n ; row ++ ) {
           if ( canPlace(row , col , board , n) ) {
                board[row][col] = 'Q';
                solve ( col + 1 , board , ans , n );
                board[row][col] = '.';
           }
       }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s ( n , '.');
        for ( int i = 0 ; i < n ; i ++ ) {
            board[i] = s;
        }
        solve ( 0 , board , ans , n );
        return ans;
    }
};