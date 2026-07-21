class Solution {
public:
    bool gcd ( char a , char b ) {
        int aa = a - '0';
        int bb = b - '0';
        while ( aa != 0 && bb != 0 ) {
            if ( aa < bb ) bb = bb % aa;
            else aa = aa % bb;
        }
        return ( aa + bb ) == 1;
    }
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int beautifulPairsCnt = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
            string s1 = to_string(nums[i]);
            for ( int j = i + 1 ; j < n ; j ++ ) {
                string s2 = to_string(nums[j]);
                int nn = s2.size();
                if ( gcd(s1[0],s2[nn-1])) beautifulPairsCnt++;
            }
        }
        return beautifulPairsCnt;
    }
};