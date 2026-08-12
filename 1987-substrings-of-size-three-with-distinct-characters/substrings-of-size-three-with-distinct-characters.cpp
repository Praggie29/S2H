class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map <string,int> st;
        for ( int i = 0 ; i + 2 < s.size() ; i ++ ) {
            if ( (s[i] != s[i + 1]) && (s[i+1] != s[i+2]) && (s[i] != s[i+2])) {
                st[(s.substr(i,3))]++;
            }
        }
        int cnt = 0;
        for ( auto &it : st ) cnt += it.second;
        return cnt;
    }
};