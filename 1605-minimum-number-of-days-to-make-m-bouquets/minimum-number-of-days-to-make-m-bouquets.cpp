class Solution {
public:
    long long f ( vector<int>& bloomDay, int m, int k , int day ) {
        long long bouquets = 0;
        long long cnt = 0;
        for ( int i = 0 ; i < bloomDay.size() ; i ++ ) {
            if ( bloomDay[i] <= day ) cnt++;
            else {
                bouquets += (cnt) / k;
                cnt = 0;
            }
        }
        bouquets += (cnt) / k;
        return bouquets;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ( 1LL*m*k > n ) return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = high;
        while ( low <= high ) {
            int mid = low + ( high - low ) / 2;
            if ( f(bloomDay,m,k,mid) >= m ) {
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