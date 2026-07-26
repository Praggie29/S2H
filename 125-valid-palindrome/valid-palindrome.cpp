class Solution {
public:
    bool check(string &sentence) {
        int n = sentence.size();
        int l = 0 , r = n - 1;
        while ( l < r ) {
            if ( sentence[l] != sentence[r] ) return false;
            l++;
            r--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string ans = "";
        for ( int i = 0 ; i < s.size() ; i ++ ) {
            char ch = s[i];
            if ( ( ch >= 'a' && ch <= 'z') || ( ch >= 'A' && ch <= 'Z') || ( ch >= '0' && ch <= '9')) {
                ans += tolower(s[i]);
            }
        }
        return check(ans);
    }
};