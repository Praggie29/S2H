class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string,int>mpp;
        for ( int i = 0 ; i < n ; i ++ ) {
            int nn = words[i].size();
            if ( nn >= k ) {
                string part = words[i].substr(0,k);
                mpp[part]++;
            }
        }
        int ans = 0;
        for ( auto& it : mpp ) {
            if ( it.second >= 2 ) {
                ans++;
            }
        }
        return ans;
    }
};