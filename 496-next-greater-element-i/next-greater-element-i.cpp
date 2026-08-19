class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>ans;
        stack<int>st;
        for ( int i = 0 ; i < m ; i ++ ) st.push(nums2[i]);
        for ( int j = 0 ; j < n ; j ++ ) {
            int maxi = -1;
            stack<int>temp = st;
            while ( !temp.empty() && temp.top() != nums1[j] ) {
                if ( temp.top() > nums1[j] ) maxi =  temp.top() ;
                temp.pop();
            }
           ans.push_back(maxi);
        }
        return ans;
    }
};