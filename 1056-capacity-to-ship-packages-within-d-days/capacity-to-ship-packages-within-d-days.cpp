class Solution {
public:
    bool solve ( vector<int>& weights, int days, int mid ) {
        int count = 1;
        int sum = 0;
        for ( int i = 0 ; i < weights.size() ; i ++ ) {
            if ( sum + weights[i] <= mid ) sum += weights[i];
            else {
                count++;
                sum = weights[i];
            }
        }
        return count <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for ( int i = 0 ; i < weights.size() ; i ++ ) sum += weights[i];
        int low = *max_element(weights.begin(),weights.end());
        int high = sum;
        int leastWeightCapacity = INT_MAX;
        while ( low <= high ) {
            int mid = low + ( high - low ) / 2;
            if ( solve(weights,days,mid) ) {
                leastWeightCapacity =  mid ;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return leastWeightCapacity;
    } 
};