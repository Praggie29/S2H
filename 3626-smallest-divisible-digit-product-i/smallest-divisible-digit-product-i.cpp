class Solution {
public:
    bool check ( int ele , int t ) {
        int store = ele;
        long long prod = 1;
        while ( store ) {
            int rem = store % 10;
            store /= 10;
            prod *= rem;
        }
        return prod % t == 0;
    }
    int smallestNumber(int n, int t) {
        int ans;
        for ( int i = n ; i <= 100 ; i ++ ) {
            if ( check(i,t) ) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};