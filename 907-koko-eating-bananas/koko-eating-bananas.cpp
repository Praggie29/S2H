class Solution {
public:
    long long f ( vector<int>& piles, int h , int speed ) {
        long long totalSpeed = 0;
        for ( int i = 0 ; i < piles.size() ; i ++ ) {
            totalSpeed = totalSpeed + ( piles[i] + (long long)speed - 1) / speed;
        }
        return totalSpeed;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = *max_element(piles.begin(),piles.end());
        int ans;
        int low = 1 , high = maxi;
        while ( low <= high ) {
            int mid = low + ( high - low ) / 2;
            if ( f(piles,h,mid) <= h ) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};