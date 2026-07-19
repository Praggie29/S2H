class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int count = 0;
        int i = 0 , j = 0;
        while ( i < n ) {
            if ( s1[i] != s2[j] ) {
                count += 1;
            }
            i ++;
            j ++;
        }
        unordered_map <char,int> mpp1,mpp2;
        for ( char ch : s1 ) mpp1[ch]++;
        for ( char ch : s2 ) mpp2[ch]++;
        return count <= 2 && mpp1 == mpp2;
    }
};