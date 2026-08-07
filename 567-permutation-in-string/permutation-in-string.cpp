class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if ( n > m ) return false;
        unordered_map <char,int> mpp1 , mpp2;
        for ( char ch : s1 ) mpp1[ch]++;
        int i = 0 , j = 0;
        while ( i <= j && j < m ) {
            mpp2[s2[j]]++;
            if ( j - i + 1 == n ) {
               if ( mpp1 == mpp2 ) return true;
               mpp2[s2[i]]--;
               if ( mpp2[s2[i]] == 0 ) mpp2.erase(s2[i]);
               i++;
            }
            j++;
        }
        return false;
    }
};