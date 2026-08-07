class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int longestSubString = INT_MIN;
        unordered_map <char,int> mpp;
        int i = 0 , j = 0;
        while ( j < n ) {
            if ( mpp.find(s[j]) == mpp.end() ) mpp[s[j]]++;
            else {
                char ch = s[j];
                while ( mpp.find(ch) != mpp.end() ) {
                    mpp[s[i]]--;
                    if ( mpp[s[i]] == 0 ) mpp.erase(s[i]);
                    i++;
                }
                mpp[s[j]]++;
            }
            longestSubString = max(longestSubString, j - i + 1);
            j++;
        }
        return longestSubString == INT_MIN ? 0 : longestSubString;
    }
};