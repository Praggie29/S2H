class Solution {
public:
    long long solve ( vector<int>& piles, int n ) {
        long long totalHours = 0;
        for ( int i = 0 ; i < piles.size() ; i ++ ) {
            if ( piles[i] <= n ) totalHours += 1;
            else {
               totalHours += ((long long)piles[i] + n - 1) / n;
            }
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1 , high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while ( low <= high ) {
            int mid = low + ( high - low ) / 2;
            long long hoursNeeded = solve(piles,mid);
            if ( hoursNeeded <= h ) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};