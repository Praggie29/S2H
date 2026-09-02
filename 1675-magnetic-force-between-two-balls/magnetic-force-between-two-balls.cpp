class Solution {
public:
    bool findMinForce ( vector<int>& position , int forceDistance , int m ) {
        int n = position.size();
        int prevBasketPos = position[0];
        int cnt = 1;
        for ( int i = 1 ; i < n ; i ++ ) {
            if ( position[i] - prevBasketPos >= forceDistance ) {
                cnt++;
                prevBasketPos = position[i];
            }
        }
        return cnt >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int low = 1;
        int high = position[n-1] - position[0];
        while ( low <= high ) {
            int mid = low + ( high - low ) / 2;
            if ( findMinForce(position,mid,m) ) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return high;
    }
};