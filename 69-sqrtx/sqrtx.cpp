class Solution {
public:
    int mySqrt(int x) {
        int low = 1 , high = x;
        int ans;
        while ( low <= high ) {
            int mid = low + ( high - low ) / 2;
            long long mul = 1LL*mid*mid;
            if ( mul == x ) { 
                ans = mid;
                break;
            }
            else if ( mul > x ) high = mid - 1;
            else {
                low = mid + 1;
                ans = mid;
            }
        }
        return ans;
    }
};