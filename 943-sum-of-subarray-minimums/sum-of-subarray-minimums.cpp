class Solution {
public:
    int M = 1e9 + 7;
    vector<int>findPSE ( vector<int>& arr , int n ) {
        stack<int>st;
        vector<int>res(n);
        for ( int i = 0 ; i < n ; i ++ ) {
            while ( !st.empty() && arr[st.top()] > arr[i]) st.pop();
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }
    vector<int>findNSE ( vector<int>& arr , int n ) {
        stack<int>st;
        vector<int>res(n);
        for ( int i = n - 1 ; i >= 0 ; i -- ) {
            while ( !st.empty() && arr[st.top()] >= arr[i]) st.pop();
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int minSubArraysSum = 0;
        vector<int>NSE = findNSE(arr,n);
        vector<int>PSE = findPSE(arr,n);
        for ( int i = 0 ; i < n ; i ++ ) {
            long long left = i - PSE[i];
            long long right = NSE[i] - i;
            long long ways = left * right * 1LL;
            minSubArraysSum = ( minSubArraysSum + ( ways * arr[i] ) % M ) % M;
        }
        return minSubArraysSum ;
    }
};