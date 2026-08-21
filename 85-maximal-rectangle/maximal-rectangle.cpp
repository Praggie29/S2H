class Solution {
public:
    vector<int> findNSE(vector<int>& nums, int n) { // Next Smaller Element
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> findPSE(vector<int>& nums, int n) { // Previous Smaller Element
        vector<int> res(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    int rect(vector<int>& heights) {
        int n = heights.size();
        int maxRectangleArea = 0;
        vector<int> PSE = findPSE(heights, n);
        vector<int> NSE = findNSE(heights, n);
        for (int i = 0; i < n; i++) {
            int area = heights[i] * (NSE[i] - PSE[i] - 1);
            maxRectangleArea = max(maxRectangleArea, area);
        }
        return maxRectangleArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0); 
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, rect(heights));
        }

        return maxArea;
    }
};