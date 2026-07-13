class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0 ) return false;
        string temp = to_string(x);
        int n = temp.size();
        int l = 0 , r = n - 1;
        while ( l <= r ) {
            if ( temp[l] == temp[r] ) {
                l++;
                r--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};