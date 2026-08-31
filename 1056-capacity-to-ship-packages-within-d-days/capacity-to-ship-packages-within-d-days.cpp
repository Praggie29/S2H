class Solution {
public:
    long long f ( vector<int>& weights, int days , int weight ) {
        long long wt = weight;
        long long daysCnt = 1;
        for ( int i = 0 ; i < weights.size() ; i ++ ) {
            if ( weights[i] <= wt ) {
                wt -= weights[i];
            }
            else {
                daysCnt++;
                wt = weight - weights[i];
            }
        }
        return daysCnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans;
        while ( low <= high ) {
            int mid = low + ( high - low ) / 2;
            if ( f(weights,days,mid) <= days ) {
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