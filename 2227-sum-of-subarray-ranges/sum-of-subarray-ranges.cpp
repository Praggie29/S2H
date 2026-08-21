class Solution {
public:
    vector<int>findNGE(vector<int>&nums , int n ) { // Next Greater Element
        vector<int>res(n);
        stack<int>st;
        for ( int i = n - 1 ; i >= 0 ; i -- ) {
           while( !st.empty() && nums[st.top()] <= nums[i]) st.pop();
           res[i] = st.empty() ? n : st.top();
           st.push(i);
        }
        return res;
    }
    vector<int>findNSE(vector<int>&nums , int n ) { // Next Smaller Element
        vector<int>res(n);
        stack<int>st;
        for ( int i = n - 1 ; i >= 0 ; i -- ) {
           while( !st.empty() && nums[st.top()] >= nums[i]) st.pop();
           res[i] = st.empty() ? n : st.top();
           st.push(i);
        }
        return res;
    }
    vector<int>findPGE(vector<int>&nums , int n ) { //Previous Greater Element
        vector<int>res(n);
        stack<int>st;
        for ( int i = 0 ; i < n ; i ++ ) {
           while( !st.empty() && nums[st.top()] < nums[i]) st.pop();
           res[i] = st.empty() ? -1 : st.top();
           st.push(i);
        }
        return res;
    }
    vector<int>findPSE(vector<int>&nums , int n ) { //Previous Greater Element
        vector<int>res(n);
        stack<int>st;
        for ( int i = 0 ; i < n ; i ++ ) {
           while( !st.empty() && nums[st.top()] > nums[i]) st.pop();
           res[i] = st.empty() ? -1 : st.top();
           st.push(i);
        }
        return res;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long totalSubArrays = 0;
        int n = nums.size();
        vector<int>NGE = findNGE(nums,n);
        vector<int>NSE = findNSE(nums,n);
        vector<int>PGE = findPGE(nums,n);
        vector<int>PSE = findPSE(nums,n);
        for (int i = 0; i < n; i++) {
           long long maxChild = (long long)(i - PGE[i]) * (NGE[i] - i);
           long long minChild = (long long)(i - PSE[i]) * (NSE[i] - i);
           totalSubArrays += (maxChild - minChild) * nums[i];
        }
        return totalSubArrays;
    }
};