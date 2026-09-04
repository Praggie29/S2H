class Solution {
public:
    
    bool find ( int i , int j , int idx , vector<vector<char>>& board, string &word , vector<vector<bool>>& visited) {
         int n = board.size();
         int m = board[0].size();
        if ( idx == word.size() ) return true;
        if ( i < 0 || j < 0 || i >= n || j >= m ) return false;
        if (board[i][j] != word[idx] || visited[i][j]) return false;
        visited[i][j] = true;
        bool found = find(i + 1, j, idx + 1, board, word, visited) ||
                     find(i - 1, j, idx + 1, board, word, visited) ||
                     find(i, j + 1, idx + 1, board, word, visited) ||
                     find(i, j - 1, idx + 1, board, word, visited);
        visited[i][j] = false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < m ; j ++ ) {
                if ( board[i][j] == word[0] && find ( i , j , 0 , board , word , visited) ) return true;
            }
        }
        return false;
    }
};