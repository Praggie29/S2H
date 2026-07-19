class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map <char,int> mpp1,mpp2;

        for ( char ch : s ) {
            mpp1[ch]++;
        }

        for ( char ch : target ) {
            mpp2[ch]++;
        }
        int noOfTargetCopies = INT_MAX;
        for ( char ch : target ) {
            int a = mpp1[ch];
            int b = mpp2[ch];
            noOfTargetCopies = min ( noOfTargetCopies , a/b );
        }
        return noOfTargetCopies;
    }
};